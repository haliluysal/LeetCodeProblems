// ConsoleApplication1.cpp: Konsol uygulamasının giriş noktasını tanımlar.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int removeDuplicates(vector<int>& nums) {
	vector<int>::iterator up;
	/* vector<int> dummy;
	int ii = 0;
	while (up != nums.end()) {
	up = upper_bound(nums.begin() + ii, nums.end(), nums[ii]);
	// nums.erase(nums.begin() + ii + 1, nums.begin() + up - 1);
	dummy.push_back(nums[ii]);
	ii = up - nums.begin();
	}
	nums = dummy; */
	int ii = 0;
	up = upper_bound(nums.begin() + ii, nums.end(), nums[ii]);
	while (up != nums.end() && ii < nums.size()) {
		nums.erase(nums.begin() + ii, up - 1);
		ii++;
		up = upper_bound(nums.begin() + ii, nums.end(), nums[ii]);
	}
	return nums.size();
}


int main()
{
	vector<int> x(3, 0);
	x.push_back(1);
	x.push_back(1);
	x.push_back(1);
	x.push_back(2);
	int n = removeDuplicates(x);
	
    return 0;
}

