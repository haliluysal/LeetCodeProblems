// ConsoleApplication1.cpp: Konsol uygulamasının giriş noktasını tanımlar.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
	bool isValid(string s) {

		stack <char> stackParantheses;
		size_t sizeOfInputString = s.size();

		for (int ii = sizeOfInputString - 1; ii >= 0; ii--)
		{
			if (s[ii] == '(' || s[ii] == ')' || s[ii] == '[' || s[ii] == ']' || s[ii] == '{' || s[ii] == '}')
			{
				stackParantheses.push(s[ii]);
			}
		}
		for (size_t ii = 0; ii < sizeOfInputString; ii++)
		{
			cout << stackParantheses.top();
			stackParantheses.pop();
		}
		return false;


		/* RECURSIVE SOLUTION */
		/* RUNS IN 172MS - BARELY PASSES TIME LIMIT */
		/*
		if (s.size() == 0)
			return true;
		for (int ii = 0; ii < s.size() - 1; ii++)
		{
			string subStr = s.substr(ii, 2);
			if (subStr == "()" || subStr == "[]" || subStr == "{}")
			{
				s.erase(s.begin() + ii, s.begin() + ii + 2);
				return isValid(s);
			}
		}
		return false;
		*/
	}
};

int main()
{
	Solution s;
	string x("(((){}[]))");
	bool ans = s.isValid(x);
    return 0;
}

