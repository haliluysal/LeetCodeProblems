// ConsoleApplication1.cpp: Konsol uygulamasının giriş noktasını tanımlar.
//

#include "stdafx.h"
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;


class Solution {
public:
	int singleNumber(vector<int>& nums) {

		unordered_set<int> setNums;
		for (int ii = 0; ii < nums.size(); ii++)
		{
			setNums.insert(nums[ii]);
			setNums.count(nums[ii]);
		}

		for (int ii = 0; ii < nums.size(); ii++)
		{
			int temp = setNums.bucket(nums[ii]);
			cout << temp << endl;
			if (setNums.bucket_size(temp) == 1)
				return 5;
		}

		return 0;
		/*int dummy = setNums.bucket_count();
		cout << dummy << endl;
		for (int ii = 0; ii < dummy; ii++)
		{
		int temp = setNums.bucket()
		}*/

		/* O(nlog(n)) complexity
		sort(nums.begin(), nums.end());
		int sizeOfVec = nums.size();
		int ii = 0;
		while (ii < sizeOfVec) {
		if (nums[ii] != nums[ii + 1])
		return nums[ii];
		ii += 2;
		}
		*/
	}
};

int main()
{
	Solution s;
	vector<int> x({ 2, 2, 1 });
	s.singleNumber(x);
    return 0;
}

