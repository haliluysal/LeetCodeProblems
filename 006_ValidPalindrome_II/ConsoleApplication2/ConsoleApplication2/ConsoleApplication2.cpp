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

	bool naiveSolution(string &s)
	{
		/*  NAIVE SOLUTION */
		/* SEARCH OVER ALL THE STRING */
		bool answer = false;
		answer = isPalindrome(s);
		if (answer == true)
			return answer;

		size_t sizeOfString = s.size();
		string dummySearchString;

		// IN THIS FOR LOOP "ANSWER" VARIABLE IS STARTING WITH FALSE.
		for (size_t ii = 0; ii < sizeOfString; ii++)
		{
			dummySearchString = s;
			dummySearchString.erase(dummySearchString.begin() + ii);
			answer = isPalindrome(dummySearchString);
			if (answer == true)
			{
				s = dummySearchString;
				return answer;
			}
		}
		return answer;
	}
	bool CheckSubStringSizes(string &s, string &subStr, const string &subStr1, const string &subStr2, const int &sizeOfSubString,
		const int &halfSizeSubStr, const int &sizeOfString, const int &ii, bool &answer)
	{
		bool ifFlag = false;
		if (subStr.size() < sizeOfSubString)
		{
			ifFlag = true;
			string dummySubStr = subStr1 + subStr2;
			for (size_t jj = 0; jj < subStr.size(); jj++)
			{
				if (subStr[jj] != dummySubStr[jj])
				{
					if (jj < halfSizeSubStr)
					{
						s.erase(s.begin() + ii * halfSizeSubStr + jj);
					}
					else
					{
						s.erase(s.begin() + sizeOfString - ((ii + 2)*halfSizeSubStr) + jj);
					}
					answer = isPalindrome(s);
					break;
				}
			}
		}
		return ifFlag;
	}

	bool validPalindrome(string s) {
		// STEP 1: CHECK WHETHER THE STRING IS ALREADY A PALINDROME OR NOT
		bool answer;
		bool ifFlag;
		answer = isPalindrome(s);
		if (answer == true)
			return answer;

		size_t sizeOfString = s.size();
		size_t sizeOfSubString = 750;
		size_t halfSizeSubStr = sizeOfSubString / 2;
		
		if (sizeOfString < 2*sizeOfSubString)
		{
			answer = naiveSolution(s); 
			return answer;
		}
		else
		{
			size_t ii = 0;
			string subStr;
			string subStr1;
			string subStr2;
			size_t halfIndx = (size_t)floor(sizeOfString / 2);
			while (((ii + 1) * halfSizeSubStr) < halfIndx)
			{
				subStr1 = s.substr(ii*halfSizeSubStr, halfSizeSubStr);
				subStr2 = s.substr(sizeOfString - ((ii+1)*halfSizeSubStr), halfSizeSubStr);
				subStr = subStr1 + subStr2;
				answer = naiveSolution(subStr);
				if (answer == false)
					return false;
				ifFlag = CheckSubStringSizes(s, subStr, subStr1, subStr2, sizeOfSubString, halfSizeSubStr, sizeOfString, ii, answer);
				if (ifFlag == true)
				{
					if (answer == true)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
				ii++;
			}
			size_t remSubStrSize = sizeOfString - (2*ii*halfSizeSubStr);
			subStr = s.substr(ii*halfSizeSubStr, remSubStrSize);
			answer = naiveSolution(subStr);
			if (answer == false)
				return false;
			ifFlag = CheckSubStringSizes(s, subStr, subStr1, subStr2, sizeOfSubString, halfSizeSubStr, sizeOfString, ii, answer);
			if (ifFlag == true)
			{
				if (answer == true)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				return answer;
			}
		}
	}
};

int main()
{
	Solution s;
	string x("zckqkbaqlujatizekfsbabowncivohtiicsvrvfuzadyrlrfqwjvarjfjqvcqxtcqkfdawvvngnemltyhspwbklqtjevtqfzuztlghfuirrdcasggogpacgiquexccfqdinosbqzersjwtxnigbqtpihmxjlhwmaypklrarivmxvaosdytatpgnxiyzadvzfactfqeerfdsrzkjzugutfgucdowkhjezkmbsjxajbqubugqmsyxnpiwegnngewipnxysmqgubuqbjaxjsbmkzejhkwodcugftuguzjkzrsdfreeqftcafzvdazyixngptatydsoavxmvirarlkpyamwhljxmhiptqbginxtwjsrezqbsonidqfccxeuqigcapgoggsacdrriufhgltlzuzfqtvejtqlkbwpshytlmengnvvwadfkqctxqcvqjfjravjwqfrlrydazufvrvsciithovicnwobabsfkezitajulqabkqkcz");
	bool ans = s.validPalindrome(x);
	return 0;
}

