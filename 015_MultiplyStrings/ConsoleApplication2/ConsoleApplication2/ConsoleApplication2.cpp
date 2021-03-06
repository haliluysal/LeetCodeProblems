// ConsoleApplication1.cpp: Konsol uygulamasının giriş noktasını tanımlar.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	Solution();
	~Solution();
	void sumTwoVect(vector<int> &outVect, vector<int> n2) {
		if (outVect.size() > n2.size())
		{
			n2.resize(outVect.size(), 0);
		}
		else
		{
			outVect.resize(n2.size(), 0);
		}

		int carry = 0;
		for (int ii = 0; ii < outVect.size(); ++ii)
		{
			outVect[ii] += (n2[ii] + carry);
			if (outVect[ii] > 9)
			{
				outVect[ii] %= 10;
				carry = 1;
			}
			else
			{
				carry = 0;
			}
		}
		if (carry == 1)
		{
			outVect.push_back(carry);
		}
	}

	string multiply(string num1, string num2) {
		int sizeOfNum1 = num1.size();
		int sizeOfNum2 = num2.size();

		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());

		vector<int> n1(sizeOfNum1, 0);
		for (int ii = 0; ii < sizeOfNum1; ii++)
		{
			n1[ii] = (int)num1[ii] - (int)'0';
		}

		vector<int> n2(sizeOfNum2, 0);
		for (int ii = 0; ii < sizeOfNum2; ii++)
		{
			n2[ii] = (int)num2[ii] - (int)'0';
		}

		vector<int> outVect(1, 0);
		for (int ii = 0; ii < n1.size(); ++ii)
		{
			//int forLim = n1[ii] * pow(10, ii);
			for (int jj = 0; jj < n1[ii]; ++jj)
			{
				sumTwoVect(outVect, n2);
			}
			n2.insert(n2.begin(), 0);
		}

		reverse(outVect.begin(), outVect.end());
		while (outVect[0] == 0 && outVect.size() > 1)
		{
			outVect.erase(outVect.begin());
		}

		string outStr = "";
		for (int ii = 0; ii < outVect.size(); ++ii)
		{
			outStr += to_string(outVect[ii]);
		}

		return outStr;
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
	string out = s.multiply("0", "15");
	return 0;
}

