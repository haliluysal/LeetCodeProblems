// ConsoleApplication1.cpp: Konsol uygulamasının giriş noktasını tanımlar.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

	bool isPalindrome(const string &s)
	{
		int sizeOfString = s.size();
		int endIdx = (int)floor(sizeOfString / 2);
		for (int ii = 0; ii < endIdx; ++ii) // Complexity O(n/2)
		{
			if (s[ii] != s[sizeOfString - ii - 1])
				return false;
		}
		return true;
	}
	bool CheckPalindrome(const string &s, const vector<pair<char, size_t>> &dummySortStringIntPair, int diff, int &ii)
	{
		bool answer = false;
		int jj = 0;
		string dummySearchString;
		while (jj < diff)
		{
			dummySearchString = s;
			dummySearchString.erase(dummySearchString.begin() + dummySortStringIntPair[ii + jj].second);
			answer = isPalindrome(dummySearchString);
			if (answer == true)
				return answer;
			++jj;
		}
		ii += diff;
		++ii;
		return answer;
	}
	

	bool validPalindrome(string s) {
		// STEP 1: CHECK WHETHER THE STRING IS ALREADY A PALINDROME OR NOT
		bool answer;
		answer = isPalindrome(s);
		size_t sizeOfString = s.size();
		if (answer == true)
			return answer;

		string dummySearchString;
		string dummySortString = s;
		vector<pair<char, size_t>> dummySortStringIntPair;
		dummySortStringIntPair.resize(sizeOfString);
		for (size_t ii = 0; ii < sizeOfString; ++ii)
		{
			pair<char, size_t> temp(s[ii], ii);
			dummySortStringIntPair[ii] = temp;
		}
		sort(dummySortStringIntPair.begin(), dummySortStringIntPair.end()); // COMPLEXITY O(nlog(n))
		sort(dummySortString.begin(), dummySortString.end()); // COMPLEXITY O(nlog(n))

		int ii = 1;
		int diff = 1;
		while (ii <= sizeOfString)
		{
			// low = lower_bound(dummySortString.begin(), dummySortString.end(), s[ii]);
			// up = upper_bound(dummySortString.begin(), dummySortString.end(), s[ii]);
			// diff = up - low;
			diff = 1;
			if (ii == sizeOfString)
			{
				--ii;
				answer = CheckPalindrome(s, dummySortStringIntPair, diff, ii);
			}
			else
			{
				while (dummySortString[ii] == dummySortString[ii - 1])
				{
					++diff;
					++ii;
				}
				cout << diff << endl;
				if (diff % 2 == 1)
				{
					ii -= diff;
					answer = CheckPalindrome(s, dummySortStringIntPair, diff, ii);
				}
				else if ((diff / 2) % 2 == 1)
				{
					ii -= diff;
					answer = CheckPalindrome(s, dummySortStringIntPair, diff, ii);
				}
				else
				{
					++ii;
				}
			}
			if (answer == true)
				return answer;
		}


		/*  NAIVE SOLUTION */
		/* SEARCH OVER ALL THE STRING */
		/* TIME LIMIT EXCEEDS */
		/*
		string dummySearchString;
		// IN THIS FOR LOOP "ANSWER" VARIABLE IS STARTING WITH FALSE.
		for (size_t ii = 0; ii < sizeOfString; ii++)
		{
		dummySearchString = s;
		dummySearchString.erase(dummySearchString.begin() + ii);
		answer = isPalindrome(dummySearchString);
		if (answer == true)
		return answer;
		}
		*/

		return answer;
	}
};

int main()
{
	Solution s;
	string x("abc");
	bool ans = s.validPalindrome(x);
    return 0;
}

