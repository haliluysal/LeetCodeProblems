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
	string multiply(string &num1, string &num2) {
		int sizeOfNum1 = num1.size();
		int sizeOfNum2 = num2.size();

		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());

		vector<int> n1(sizeOfNum1, 0);
		for (int ii = 0; ii < num1.size(); ii++)
		{

		}
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

