// ConsoleApplication1.cpp: Konsol uygulamasının giriş noktasını tanımlar.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution
{
public:
	Solution();
	~Solution();
	vector<vector<int>> ChunkVect(vector<int> &nums, int chunkSize)
	{
		vector<vector<int>> res;
		int sizeOfVect = nums.size();

		/* SECOND SOLUTION */
		res.resize(ceil(sizeOfVect / (double)chunkSize));
		int ii = 0;
		while (ii < sizeOfVect)
		{
			res[ii / chunkSize].push_back(nums[ii]);
			ii++;
		}
		return res;


		/* FIRST SOLUTION */
		/*if (sizeOfVect < chunkSize)
		{
			res.push_back(nums);
			return res;
		}
		else
		{
			int ii = 0;
			int idx = 0;
			res.resize(ceil(sizeOfVect / (double)chunkSize));
			while (ii < sizeOfVect)
			{
				if ((ii + chunkSize) < sizeOfVect)
				{
					res[idx].resize(chunkSize, 0);
					for (int jj = 0; jj < chunkSize; jj++)
					{
						res[idx][jj] = nums[ii];
						ii++;
					}
				}
				else
				{
					res[idx].resize(sizeOfVect - idx*chunkSize, 0);
					for (int jj = 0; jj < (sizeOfVect - idx*chunkSize); jj++)
					{
						res[idx][jj] = nums[ii];
						ii++;
					}
				}
				idx++;
			}
			return res;
		}*/
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
	Solution s;
	vector<int> x = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
	vector<vector<int>> y = s.ChunkVect(x, 3);
    return 0;
}

