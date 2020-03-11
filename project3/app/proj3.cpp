#include "proj3.hpp"
#include <vector>
#include <queue> // std::priority_queue lives here. 
#include <limits> // for UINT_MAX

std::vector<unsigned> TSP_via_NNA(const std::vector< std::vector<unsigned> > & graph, unsigned start)
{
	unsigned size = graph.size();
	std::vector<unsigned> journey;
	std::vector<bool> visited(size, false); // Mark a vertex if it's visited, set value to true. Initially set to false
	unsigned current = start; // the index of currently visited vertex
	while(journey.size() < size)
	{
	    journey.push_back(current);
	    visited[current] = true;
		unsigned nextVer = -1, minimum = UINT_MAX;
		for(unsigned temp = 0; temp < size; temp++)
		{
			if(!visited[temp] && current != temp)
			{
				// if find a nearer neighbor
				if(graph[current][temp] < minimum)
				{
					minimum = graph[current][temp];
					nextVer = temp;
				}
			}
		}
		current = nextVer;
	}
	return journey;
}


std::vector<unsigned> TSP_via_greedyEdge(const std::vector< std::vector<unsigned> > & graph)
{   
    unsigned size = graph.size();
    std::vector<unsigned> journey(size);
    // min queue
    std::priority_queue<Edge, std::vector<Edge>> edgeQueue;
    // sort all the edges according to their weights in non-decreasing order
    for(unsigned i=0; i<size-1; i++)
    {
        for(unsigned j=i+1; j<size; j++)
        {   
            edgeQueue.push(Edge(i, j, graph[i][j])); 
        }
    }
    // Keep track of the degree of each vertex
    std::vector<unsigned> degree(size, 0);
    // Count how many edges are in the journey
    unsigned count = 0;
    // For marking the edges in the graph, and there's an edge if markedGraph[i][j]=true
    std::vector<std::vector<bool>> markedGraph(size, std::vector(size, false));
    // Select edge with smallest weight from queue until all the (size-1) edges are in the journey
    while(count < size-1)
    {
        Edge curEdge = edgeQueue.top();
        edgeQueue.pop();
        unsigned ver1 = curEdge.pt1, ver2 = curEdge.pt2;
        // if adding this edge does not violate that both end vertics have degree greater than and equal to 2
        if(degree[ver1]<2 && degree[ver2]<2)
        {
            // Since the graph is undirected, we need to mark the selected edge twice
            markedGraph[ver1][ver2] = true;
            markedGraph[ver2][ver1] = true;
            degree[ver1]++;
            degree[ver2]++;
        }
        count++;
    }

    // Generate the journey from the selected edges
    count = 0;
    unsigned curVer = 0;
    journey[count] = curVer;
    while(count < size-1)
    {
        for(unsigned nextVer=0; nextVer<size; nextVer++)
        {
            if(curVer != nextVer && markedGraph[curVer][nextVer] == true)
            {
                markedGraph[curVer][nextVer] = false;
                markedGraph[nextVer][curVer] = false;
                curVer = nextVer;
                journey[count+1] = curVer;
                count++;
            }
        }
    }
	return journey;
}


std::vector< std::vector<unsigned> > orderCrossover(const std::vector<unsigned> & j1, const std::vector<unsigned> & j2, 
                                                        unsigned pickStart, unsigned pickLen)
{
    std::vector< std::vector<unsigned> > children; // (2, std::vector<unsigned>());

    // I found it easier to start with the child of the right size
    // and use indexing to place the right elements.
    // Feel free to do something different.
    std::vector<unsigned> oneChild(j1.size());  
    std::vector<unsigned> otherChild(j2.size());    
    
    std::vector<unsigned> segment1 = std::vector<unsigned> (j1.begin() + pickStart, j1.begin() + pickStart + pickLen);
    std::vector<unsigned> segment2 = std::vector<unsigned> (j2.begin() + pickStart, j2.begin() + pickStart + pickLen);

    // compute one child
    unsigned pivot = 0;
    // create template
    for(unsigned i=pickStart; i<j1.size(); i++){
        if(std::find(segment2.begin(), segment2.end(), j1[i]) == segment2.end()){
            otherChild[pivot] = j1[i];
            pivot++;
        }
        if(pivot == pickStart)
            pivot = pickStart + pickLen;
    }
    for(unsigned i=0; i<pickStart; i++){
        if(std::find(segment2.begin(), segment2.end(), j1[i]) == segment2.end()){
            otherChild[pivot] = j1[i];
            pivot++;
        }
    }
    // assign kept parent
    for(unsigned i=pickStart; i<pickStart + pickLen; i++){
        otherChild[i] = j2[i];
    }
    
    // compute the other child
    pivot = 0;
    // create template
    for(unsigned i=pickStart; i<j2.size(); i++){
        if(std::find(segment1.begin(), segment1.end(), j2[i]) == segment1.end()){
            oneChild[pivot] = j2[i];
            pivot++;
        }
        if(pivot == pickStart)
            pivot = pickStart + pickLen;
    }
    for(unsigned i=0; i<pickStart; i++){
        if(std::find(segment1.begin(), segment1.end(), j2[i]) == segment1.end()){
            oneChild[pivot] = j2[i];
            pivot++;
        }
    }
    // assign kept parent
    for(unsigned i=pickStart; i<pickStart + pickLen; i++){
        oneChild[i] = j1[i];
    }
    
    // Hint to make debugging and writing easier: 
    //      the procedure for one child and the other child is the same
    //      with a minor change.
    children.push_back( oneChild );
    children.push_back( otherChild );


    return children;
}



std::vector<unsigned> mutation(const std::vector<unsigned> & journey, unsigned mutateStart, unsigned mutateLength)
{
    // This starts with result as a copy of the initial journey.
    // As always, feel free to start differently (as long as your result is correct)
    std::vector<unsigned> result(journey);
    unsigned end = mutateStart + mutateLength - 1;
    // reverse
    for(unsigned start=mutateStart; start<mutateStart + mutateLength; start++){
        result[start] = journey[end];
        end--;
    }

    return result; 
}



std::vector<unsigned> unionGraphReproduce(const std::vector<unsigned> & j1, const std::vector<unsigned> & j2, 
										const std::vector< std::vector<unsigned> > & graph, unsigned start, unsigned numFromUnion)
{
    unsigned size = graph.size();
	std::vector<unsigned> journey(size);
    // initialize an empty unionGraph and a full copy of graph
    std::vector<std::vector<unsigned>> unionGraph(size, std::vector<unsigned>(size, 0)), tempGraph = graph;
    // construct the unionGraph
    for(unsigned verNum = 0; verNum < j1.size()-1; verNum++)
    {
        unionGraph[j1[verNum]][j1[verNum+1]] = graph[j1[verNum]][j1[verNum+1]];
        unionGraph[j2[verNum]][j2[verNum+1]] = graph[j2[verNum]][j2[verNum+1]];
    }
    unsigned curVer = start, count = 0;
    journey[count++] = curVer;
    // Select first numFromUnion edges
    for(unsigned verNum = 0; verNum < numFromUnion; verNum++)
    {
        unsigned nextVer = -1, minDis = UINT_MAX;
        // if get stuck in the union graph or not
        bool getStuck = true;
        for(unsigned tempVer = 0; tempVer < size; tempVer++)
        {
            // if there's a shorter edge
            if(unionGraph[curVer][tempVer] > 0 && unionGraph[curVer][tempVer] < minDis)
            {
                getStuck = false;
                minDis = unionGraph[curVer][tempVer];
                nextVer = tempVer;
            }
        }
        if(!getStuck)
        {
            unionGraph[curVer][nextVer] = 0;
            tempGraph[curVer][nextVer] = 0;
            // should not go to the same edge again from another direction
            unionGraph[nextVer][curVer] = 0;
            tempGraph[nextVer][curVer] = 0;
            curVer = nextVer;
            journey[count++] = curVer;
        }
        // if get stuck, draw from the full graph
        else 
        {
            break;
        }
    }
    // get the remaining journey from the full graph
    while(count < size)
    {
        unsigned nextVer = -1, minDis = UINT_MAX;
        for(unsigned tempVer = 0; tempVer < size; tempVer++)
        {
            // if there's a shorter edge
            if(tempGraph[curVer][tempVer] > 0 && tempGraph[curVer][tempVer] < minDis)
            {
                minDis = tempGraph[curVer][tempVer];
                nextVer = tempVer;
            }
        }
        tempGraph[curVer][nextVer] = 0;
        // should not go to the same edge again from another direction
        tempGraph[nextVer][curVer] = 0;
        curVer = nextVer;
        journey[count++] = curVer;
    }
	return journey; 
}
