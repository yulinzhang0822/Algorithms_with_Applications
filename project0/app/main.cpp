#include <iostream>
#include <vector>
#include "proj0.hpp"



int main()
{
	// Feel free to use main() as you desire, if that is your preference.
	// Remember grading is done via gtest not by manually running your program!
    std::vector< std::vector< long > > distances = {{0, 2, 9, 1000}, 
                                                    {1, 0, 6, 4}, 
                                                    {1000, 7, 0, 8}, 
                                                    {6, 3, 1000, 0}};
    std::vector<unsigned> result(4);
    result = tsp_bruteforce(distances, 4);
    for(auto i = 0; i < 4; i++)
    {
        std::cout<< result[i] << " ";
    }
    std::cout<<std::endl;
    return 0;
}

