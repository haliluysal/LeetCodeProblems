// ConsoleApplication1.cpp: Konsol uygulamasının giriş noktasını tanımlar.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	Solution();
	~Solution();
	vector<int> twoSum(vector<int> nums, int target)
	{
		unordered_map<int, int> mm;
		vector<int> result;
		int numToFind = 0;

		for (size_t ii = 0; ii < nums.size(); ii++)
		{
			numToFind = target - nums[ii];
			if (mm.find(numToFind) != mm.end())
			{
				result.push_back(mm[numToFind]);
				result.push_back(ii);
				return result;
			}
			mm[nums[ii]] = ii;
		}
		return result;
	}

private:

};

Solution::Solution()
{
}

Solution::~Solution()
{
}

int main()
{
    return 0;
}

