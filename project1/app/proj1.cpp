#include "proj1.hpp"
#include <iostream> // for debug purposes, see project description for a suggestion.
#include <limits> // for UINT_MAX
#include <vector>
using namespace std;

// Solve TSP exactly, using dynamic programming.
// The grading script will use this exact function signature, so do not change it!
// The graph is given as an adjacency matrix, HOWEVER, no edges have a cost of '0'.
// The value graph[i][j] tells you the cost of an edge from i TO j.  This graph is directed.
// 		However, if graph[i][j]==0, this means there is no edge from i to j, instead of having one of that cost.
std::vector<unsigned> tsp_dynamic_program(const std::vector<std::vector<long>> & graph, unsigned n)
{
	std::vector<unsigned> journey;

    // get a copy of graph
	vector<vector<long>> path_map = graph;
    
    // path_num is the number of subsets in the vertex set V (excluding starting vertex v0)
	long path_num = 1 << (n-1);
    // dp is a matrix to store previous results
	vector<vector<long> > dp(n, vector<long>(path_num));
	vector<vector<long> > path(n, vector<long>(path_num));

    // set all the edges with cost of 0 (no edge) to be UINT_MAX
	for(long i=0; i<n; i++){
		for(long j=0; j<n; j++){
			if(path_map[i][j] == 0)
				path_map[i][j] = UINT_MAX;
		}
	}

    // base case: directly from vi to v0
	for(long i=0; i<n; i++)
		dp[i][0] = path_map[i][0];

    // other cases
	for(long j=1; j<path_num; j++){
        // start from i, going to vertices represented by j in bits
		for(long i=0; i<n; i++){
			dp[i][j] = UINT_MAX;
            // for j, check if it's i-th digit is 1 (if have already visted j, continue)
			if(((j >> (i-1)) & 1) == 1)
				continue;
            // check if can go to vertice k first
			for(long k=1; k<n; k++){
                // for j, check if it's k-th digit is 0 (if not, continue)
				if(((j >> (k-1)) & 1) == 0)
					continue;
                // update the path of less cost
				if(dp[i][j] > path_map[i][k] + dp[k][j^(1<<(k-1))]){
					dp[i][j] = path_map[i][k] + dp[k][j^(1<<(k-1))];
					path[i][j] = k;
				}
			}
		}
	}

    // get the path by backtracking
	journey.push_back(0);
	for(long j=path_num-1,i=0; j>0;){
		i = path[i][j];
		j = j - (1 << (i-1));
		journey.push_back(i);
	}

	// fix journey to start at 0.
	// This code segment assumes that the vector has a 0 somewhere
	//		and "rotates" the journey so that the zero is at the front.
	// Feel free to use, change, disregard, or delete as you see fit.
	// It is commented out right now because journey is empty.
/*
	while( journey[0] != 0 )
	{
		journey.push_back(journey[0]);
		journey.erase( journey.begin() );
	}
*/
	return journey; 
}


// Returns the cost of the journey described here.
long costOfJourney(const std::vector<std::vector<long>> & graph, const std::vector<unsigned> & journey)
{	
	long cost = 0;
	for(auto j = 0; j < journey.size()-1; j++){
		cost += graph[journey[j]][journey[j+1]];
	}
	cost += graph[journey[journey.size()-1]][journey[0]];
	return cost;
}
