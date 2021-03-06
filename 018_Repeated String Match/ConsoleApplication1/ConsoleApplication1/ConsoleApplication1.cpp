// ConsoleApplication1.cpp: Konsol uygulamasının giriş noktasını tanımlar.
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
	int repeatedStringMatch(string A, string B) {
		int sizeOfStringA = A.size();
		int sizeOfStringB = B.size();
		string concatanatedString = A;

		int counter = 1;
		while (concatanatedString.size() < 100 * sizeOfStringB) {
			int posOfSubString = A.find(B);
			if (posOfSubString != string::npos) {
				return counter;
			}
			concatanatedString += A;
		}
		
		return -1;
	}
};

int main()
{
	Solution s;
	int x = s.repeatedStringMatch("abcd", "dab");
    return 0;
}

