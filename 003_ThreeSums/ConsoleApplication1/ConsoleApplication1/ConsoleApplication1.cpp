// ConsoleApplication1.cpp: Konsol uygulamasının giriş noktasını tanımlar.
//

#include "stdafx.h"

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<pair<int, int>> twoSum(vector<int>& nums, int target) {
		// output vector
		vector<pair<int, int>> result;

		vector<pair<int, int>> nums2;
		for (int i = 0; i < nums.size(); ++i) {
			pair<int, int> temp(nums[i], i);
			nums2.push_back(temp);
		}

		int ii = 0;
		int jj = nums.size() - 1;
		int sum = 0;

		// sort(nums2.begin(), nums2.end()); // O(nlog(n)) complexity


		while (ii < jj) { // O(n) Complexity
			sum = nums2[ii].first + nums2[jj].first;
			if (sum == target) { // O(1) complexity
				result.resize(2);
				result[0] = nums2[ii];
				result[1] = nums2[jj];
				return result;
			}
			else if (sum > target)
				--jj;
			else if (sum < target)
				++ii;
		}
		return result;
	}



	vector<vector<int>> threeSum(vector<int>& nums) {

		bool flag;
		int totalDeletion;
		sort(nums.begin(), nums.end());
		vector<int> values(3, 0);
		vector<int>::iterator up1, up2, low1, low2;
		vector<vector<int>> result;
		int sizeOfNums = nums.size();
		pair<int, int> temp(0, 0);
		vector<pair<int, int>> twoSumResult;
		if (sizeOfNums > 3) {
			for (int ii = 0; ii < sizeOfNums; ++ii) {
				twoSumResult.push_back(temp);
				vector<int> dummy(nums.begin() + ii + 1, nums.end());
				while (dummy.size() > 1 && twoSumResult.size() > 0) {
					flag = false;
					twoSumResult = twoSum(dummy, -nums[ii]);
					if (twoSumResult.size() > 1) {
						values[0] = nums[ii];
						values[1] = twoSumResult[0].first;
						values[2] = twoSumResult[1].first;
						sort(values.begin(), values.end());

						up1 = upper_bound(dummy.begin(), dummy.end(), twoSumResult[0].first);
						low1 = lower_bound(dummy.begin(), dummy.end(), twoSumResult[0].first);
						up2 = upper_bound(dummy.begin(), dummy.end(), twoSumResult[1].first);
						low2 = lower_bound(dummy.begin(), dummy.end(), twoSumResult[1].first);

						if ((up1 - low1) > 1 && (up2 - low2) > 1)
						{
							if (up1 - low1 > up2 - low2)
							{
								totalDeletion = up2 - low2;
							}
							else
							{
								totalDeletion = up1 - low1;
							}
							if (twoSumResult[0].second > twoSumResult[1].second)
							{
								dummy.erase(low1, up1);
								if (dummy.size() > twoSumResult[0].second + totalDeletion - 1)
								{
									dummy.erase(dummy.begin() + twoSumResult[1].second, dummy.begin() + twoSumResult[1].second + totalDeletion - 1);
								}
							}
							else
							{
								dummy.erase(low2, up2);
								if (dummy.size() > twoSumResult[0].second + totalDeletion - 1)
								{
									dummy.erase(dummy.begin() + twoSumResult[0].second, dummy.begin() + twoSumResult[0].second + totalDeletion - 1);
								}
							}
						}
						else
						{
							if (twoSumResult[0].second > twoSumResult[1].second)
							{
								dummy.erase(dummy.begin() + twoSumResult[0].second);
								dummy.erase(dummy.begin() + twoSumResult[1].second);
							}
							else
							{
								dummy.erase(dummy.begin() + twoSumResult[1].second);
								dummy.erase(dummy.begin() + twoSumResult[0].second);
							}
						}

						if (result.size() > 0) {
							for (int jj = 0; jj < result.size(); ++jj) {
								if (result[jj][0] == values[0] && result[jj][1] == values[1] && result[jj][2] == values[2]) {
									flag = true;
								}
							}
							if (flag == false) {
								result.push_back(values);
							}
						}
						else
							result.push_back(values);
					}
				}
			}
		}
		else if (sizeOfNums == 3) {
			if (nums[0] + nums[1] + nums[2] == 0) {
				values[0] = nums[0];
				values[1] = nums[1];
				values[2] = nums[2];
				sort(values.begin(), values.end());
				result.push_back(values);
			}
		}
		return result;
	}
};

int main()
{
	Solution s;
	vector<int> xx{-3,-4,-2,0,2,2,-2,1,-1,2,3,-1,-5,-4,-5,1};
	s.threeSum(xx);
    return 0;
}

