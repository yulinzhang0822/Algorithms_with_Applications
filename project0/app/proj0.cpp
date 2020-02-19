#include "proj0.hpp"
#include <algorithm>
#include <iostream>

// NOTE:  This is a sample designed to show you one way to generate all 
// permutations in a graph.  It is NOT a correct answer.
// I encourage you to read this code, understand what it does, 
// and ask questions if you have any.
// Then, your understanding should help you finish the assignment. 
std::vector<unsigned> tsp_bruteforce(const std::vector<std::vector<long>> & graph, unsigned n)
{
	unsigned i;
	std::vector<unsigned> perms(n), result(n);
	for (i =0; i < n; i++)
	{
		perms[i] = i;
	}
    
    long smallestCost = UINT_MAX, tempCost = 0;

	do
	{
        tempCost = costOfJourney(graph, perms);
	    if(tempCost < smallestCost)
        {
            smallestCost = tempCost;
            result = perms;
        }
	}while( std::next_permutation(perms.begin(), perms.end()));
	return result; 
}


long costOfJourney(const std::vector<std::vector<long>> & graph, const std::vector<unsigned> & journey)
{
    long cost = 0;
    for(unsigned i = 0; i < journey.size()-1; i++)
    {
        cost += graph[journey[i]][journey[i+1]];
    }
    cost += graph[journey[journey.size()-1]][journey[0]];
	return cost;
}

