#include <iostream>
#include "proj2.hpp"
#include <queue> // This is where std::priority_queue lives.
#include <stack> // you may want std::stack for your depth-first traversal.
using namespace std;

// Your function MAY assume that this is a complete graph (as that is part of project specification).
std::vector<Edge> compute_mst(std::vector< std::vector<unsigned>> & graph)
{
    std::vector<Edge> mst;
    std::priority_queue<Edge, std::vector<Edge>> edgeQueue;
    unsigned size = graph.size();
    // Whether vertex i is in the MST or not
    std::vector<bool> confirmed(size, false);
    // Start from vertex 0, curVerNum is the current vertex being visited
    unsigned curVerNum = 0;
    confirmed[curVerNum] = true;
    // Count how many vertices are already in the MST
    unsigned count = size - 1;
    for(unsigned verNum = 1; verNum < size; verNum++)
    {
        edgeQueue.push(Edge(curVerNum, verNum, graph[curVerNum][verNum]));
    }
    // If there still remain unconfirmed vertices
    while(count > 0)
    {
        Edge tempEdge = edgeQueue.top();
        edgeQueue.pop();
        curVerNum = tempEdge.pt2;
        // Check if the current vertex has been confirmed
        // If not, push the edge into the MST
        if(!confirmed[curVerNum])
        {
            mst.push_back(tempEdge);
            confirmed[curVerNum] = true;
            count--;
            for(unsigned verNum = 0; verNum < size; verNum++)
            {
                // Make sure the adjacent vertex is different from the current vertex
                // And the adjacent vertex is not confirmed yet
                if(verNum != curVerNum && !confirmed[verNum])
                {
                    edgeQueue.push(Edge(curVerNum, verNum, graph[curVerNum][verNum]));
                }
            }
        }
    }
    return mst;
}


// Returns the cost of the edges in the given vector,
// This does not confirm that it is a MST at all.
unsigned mstCost(const std::vector<Edge> & vE) 
{
    unsigned sum =0;
    for(auto e: vE)
    {
        sum += e.weight;
    }
    return sum;
}

// reuse the code from our project 1
unsigned costOfJourney(const std::vector<std::vector<unsigned>> & graph, const std::vector<unsigned> & journey)
{
    unsigned cost = 0;
    for(auto i = 0; i < journey.size() - 1; i++)
    {
        cost += graph[journey[i]][journey[i+1]];
    }
    cost += graph[journey[journey.size()-1]][journey[0]];
    return cost; 
}

unsigned waste(const std::vector<Edge> & tree, const std::vector<unsigned> & journey, const std::vector<std::vector<unsigned>> & graph)
{
    unsigned difference = costOfJourney(graph, journey) - mstCost(tree);
    return difference;
}

// run dfs on mst and record visited vertices, which compose the path
// stack iterative version
std::vector<unsigned> computeTSPJourney(const std::vector< Edge > & mst, unsigned start)
{
    std::vector<unsigned> journey;
    // without the original graph input
    // look for the largest vertex number in mst to get the graph size
    unsigned size = 0;
    for(auto edges:mst){
        if(edges.pt1 > size || edges.pt2 > size)
            size = edges.pt1 ? edges.pt2 : edges.pt1 > edges.pt2;
    }
    size++;
    // iterative DFS, use a stack to store vertices and a visited array to avoid loop
    vector<bool> visited(size, false);
    stack<unsigned> vertex_st;
    vertex_st.push(start);
    while(!vertex_st.empty()){
        vector<unsigned> adjacent;
        unsigned curr = vertex_st.top();
        vertex_st.pop();
        visited[curr] = true;
        for(int i=0; i<mst.size(); i++){
            if(mst[i].pt1 == curr)
                adjacent.push_back(mst[i].pt2);
        }
        for(int i=0; i<adjacent.size(); i++){
            int next = adjacent[i];
            if(!visited[next])
                vertex_st.push(next);
        }
        // put current visited vertex to the final path
        journey.push_back(curr);
    }
    return journey; 
}
/*
// recursive version, using more functions
bool findInMST(vector<Edge> mst, unsigned u, unsigned v){
    for(int i=0; i<mst.size(); i++){
        if(mst[i].pt1 == u && mst[i].pt2 == v)
            return true;
    }
    return false;
}

void dfs(vector<Edge> mst, vector<unsigned> &journey, vector<bool> &visited, unsigned v, unsigned size){
    journey.push_back(v);
    visited[v] = true;
    for(int i=0; i<size; i++){
        if(findInMST(mst, v, i) && !visited[i])
            dfs(mst, journey, visited, i, size);
    }
}

std::vector<unsigned> computeTSPJourney(const std::vector< Edge > & mst, unsigned start)
{
    std::vector<unsigned> journey;
    unsigned size = 0;
    for(auto edges:mst){
        if(edges.pt1 > size || edges.pt2 > size)
            size = edges.pt1 ? edges.pt2 : edges.pt1 > edges.pt2;
    }
    size++;
    vector<bool> visited(size, false);
    dfs(mst, journey, visited, 0, size);
    return journey; 
}*/
