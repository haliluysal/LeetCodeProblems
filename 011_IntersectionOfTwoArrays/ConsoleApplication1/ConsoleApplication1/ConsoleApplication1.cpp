// ConsoleApplication1.cpp: Konsol uygulamasının giriş noktasını tanımlar.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		unordered_set<int> s1;
		unordered_set<int> s2;
		vector<int> res;
		for (size_t ii = 0; ii < nums1.size(); ii++)
		{
			s1.insert(nums1[ii]);
		}
		for (size_t ii = 0; ii < nums2.size(); ii++)
		{
			s2.insert(nums2[ii]);
		}
		for (size_t ii = 0; ii < s1.size(); ii++)
		{
			if (s2.find(*s1.begin() + ii) != s2.end())
			{
				res.push_back(*s1.begin() + ii);
			}
		}
		return res;
	}
};

int main()
{
	vector<int> nums1({ 1, 2, 4, 10 });
	vector<int> nums2({ 1, 1, 4, 2 });
	Solution s;
	vector<int> nums3 = s.intersection(nums1, nums2);
    return 0;
}

