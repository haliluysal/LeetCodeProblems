// ConsoleApplication1.cpp: Konsol uygulamasının giriş noktasını tanımlar.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		int len = nums.size();
		for (int i = 0; i<len; i++) {
			int m = abs(nums[i]) - 1; // index start from 0
			nums[m] = nums[m]>0 ? -nums[m] : nums[m];
		}
		vector<int> res;
		for (int i = 0; i<len; i++) {
			if (nums[i] > 0) res.push_back(i + 1);
		}
		return res;
	}
};

int main()
{
	Solution s;
	vector<int> x({ 1,3,7,6,5,5,2 });
	vector<int> y = s.findDisappearedNumbers(x);
    return 0;
}

