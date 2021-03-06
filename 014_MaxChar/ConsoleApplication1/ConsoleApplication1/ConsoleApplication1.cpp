// ConsoleApplication1.cpp: Konsol uygulamasının giriş noktasını tanımlar.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	Solution();
	~Solution();
	char FindMaxChar(string s) {
		unordered_map<char, int> mapOfString;
		for(char c : s)
		{
			mapOfString[c]++;
		}

		char outRes;
		int mxCnt = -1;
		auto it = mapOfString.begin();
		while (it != mapOfString.end())
		{
			if (it->second > mxCnt)
			{
				mxCnt = it->second;
				outRes = it->first;
			}
			++it;
		}
		return outRes;
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
	char c = s.FindMaxChar("Hello World!!");
    return 0;
}

