#include <vector>
#include <gtest/gtest.h>
#include "proj0.hpp"

namespace{

	TEST(SampleTests, TestCostOfJourney)
	{
		std::vector< std::vector< long > > distances = 
		{
				{0, 2, 9, 1000}, 
				{1, 0, 6, 4}, 
				{1000, 7, 0, 8}, 
				{6, 3, 1000, 0}
		};
		std::vector<unsigned> journey = {0, 2, 3, 1};
		EXPECT_TRUE( costOfJourney(distances, journey) == 21);
	}

	TEST(SampleTests, TestFindJourney)
	{
		std::vector< std::vector< long > > distances = 
		{
				{0, 2, 9, 1000}, 
				{1, 0, 6, 4}, 
				{1000, 7, 0, 8}, 
				{6, 3, 1000, 0}
		};
		std::vector<unsigned> expected = {0, 2, 3, 1};
		EXPECT_TRUE( tsp_bruteforce(distances, 4) == expected );

	}

}
