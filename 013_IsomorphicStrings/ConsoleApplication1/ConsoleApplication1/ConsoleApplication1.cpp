// ConsoleApplication1.cpp: Konsol uygulamasının giriş noktasını tanımlar.
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
	bool isIsomorphic(string s, string t) {
		if (s.size() != t.size())
		{
			return false;
		}

		unordered_map<char, char> mp1, mp2;

		for (size_t ii = 0; ii < s.size(); ii++)
		{
			// if (mp1.find(s[ii]) == mp1.end())
			// {
			mp1[s[ii]] = t[ii];
			// }
			// if (mp2.find(t[ii]) == mp2.end())
			// {
			mp2[t[ii]] = s[ii];
			// }
			// cout << mp1[s[ii]] << mp2[t[ii]] << endl;
		}
		if (mp1.size() != mp2.size())
			return false;
		for (size_t ii = 0; ii < s.size(); ii++)
		{
			// cout << mp1[s[ii]] << "\t" << t[ii] << "\t" << mp2[t[ii]] << "\t" << s[ii] << endl;
			/* if (mp1[s[ii]] == t[ii] && mp2[t[ii]] == s[ii])
			{
			continue;
			}
			else
			{
			return false;
			}*/
			if (mp1[s[ii]] != t[ii] || mp2[t[ii]] != s[ii])
			{
				return false;
			}
		}
		return true;
	}
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
	bool x = s.isIsomorphic("egghh", "addgg");
    return 0;
}

