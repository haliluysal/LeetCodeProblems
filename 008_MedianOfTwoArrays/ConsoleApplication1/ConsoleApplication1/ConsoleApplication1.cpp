// ConsoleApplication1.cpp: Konsol uygulamasının giriş noktasını tanımlar.
//

#include "stdafx.h"
#include <vector>
#include <list>

using namespace std;

//struct node
//{
//	int value;
//	node *next = NULL;
//};

class Solution {
public:
	

	double findMedian(const vector<int> &nums)
	{
		size_t sizeOfNums = nums.size();
		if (sizeOfNums % 2 == 0)
		{
			size_t idx1 = (size_t)((sizeOfNums - 1) / 2);
			size_t idx2 = (size_t)((sizeOfNums + 1) / 2);
			return (((double)nums[idx1] + (double)nums[idx2]) / 2);
		}
		else
		{
			return (nums[(sizeOfNums - 1) / 2]);
		}
	}

	bool mycomparison(int first, int second)
	{
		return (first < second);
	}

	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

		size_t sizeOfNums1 = nums1.size();
		size_t sizeOfNums2 = nums2.size();


		// cover the corners
		if (sizeOfNums1 == 0 && sizeOfNums2 == 0)
			return 0.0;
		else if (sizeOfNums1 != 0 && sizeOfNums2 == 0)
			return findMedian(nums1);
		else if (sizeOfNums1 == 0 && sizeOfNums2 != 0)
			return findMedian(nums2);
		else
		{
			if (sizeOfNums1 == 1 && sizeOfNums2 == 1)
			{
				nums1.resize(2);
				nums1[1] = nums2[0];
				return findMedian(nums1);
			}
			list<int> numsList;
			list<int> dummyList;
			for (size_t ii = 0; ii < sizeOfNums1; ii++)
			{
				numsList.push_back(nums1[ii]);
			}

			for (size_t ii = 0; ii < sizeOfNums2; ii++)
			{
				dummyList.push_back(nums2[ii]);
			}

			numsList.merge(dummyList, mycomparison);
			vector<int> numsVec(sizeOfNums1 + sizeOfNums2, 0);
			for (size_t ii = 0; ii < sizeOfNums1 + sizeOfNums2; ii++)
			{
				numsVec[ii] = numsList.front();
				numsList.pop_front();
			}
			return findMedian(numsVec);
		}
	}
};

int main()
{
    return 0;
}

