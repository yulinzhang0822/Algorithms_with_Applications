#include "proj3.hpp"
#include <vector>
#include <queue> // std::priority_queue lives here. 


std::vector<unsigned> TSP_via_NNA(const std::vector< std::vector<unsigned> > & graph, unsigned start)
{
	std::vector<unsigned> journey;
	return journey;
}


std::vector<unsigned> TSP_via_greedyEdge(const std::vector< std::vector<unsigned> > & graph)
{
	std::vector<unsigned> journey;
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

	// Hint to make debugging and writing easier: 
	//		the procedure for one child and the other child is the same
	//		with a minor change.
	children.push_back( oneChild );
	children.push_back( otherChild );


	return children;
}



std::vector<unsigned> mutation(const std::vector<unsigned> & journey, unsigned mutateStart, unsigned mutateLength)
{
	// This starts with result as a copy of the initial journey.
	// As always, feel free to start differently (as long as your result is correct)
	std::vector<unsigned> result(journey);

	return result; 
}



std::vector<unsigned> unionGraphReproduce(const std::vector<unsigned> & j1, const std::vector<unsigned> & j2, 
										const std::vector< std::vector<unsigned> > & graph, unsigned start, unsigned numFromUnion)
{

	std::vector< unsigned> journey;

	return journey; 
}


