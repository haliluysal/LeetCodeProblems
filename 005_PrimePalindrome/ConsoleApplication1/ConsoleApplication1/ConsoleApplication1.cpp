// ConsoleApplication1.cpp: Konsol uygulamasının giriş noktasını tanımlar.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> primeNumberVec{ 2, 3, 5, 7, 11, 13 };
	bool CheckPalindrome(int n)
	{
		vector<int> nVec(10, 0);
		for (int ii = 0; ii < 10; ++ii)
		{
			nVec[ii] = floor(n / pow(10, 9 - ii));
			n -= (nVec[ii] * pow(10, 9 - ii));
		}

		// Check first non-zero integer
		while (nVec[0] == 0)
		{
			nVec.erase(nVec.begin());
		}

		int nSize = nVec.size();
		int endIdx = floor(nSize / 2);
		for (int ii = 0; ii < endIdx; ++ii)
		{
			if (nVec[ii] != nVec[nSize - ii - 1])
				return false;
		}
		return true;
	}

	bool CheckPrime(int n)
	{
		bool isPrime;
		if (n >= 2)
			isPrime = true;
		else
			return false;
		
		// int endIdx = floor(sqrt(n / 2)) > primeNumberVec[5] ? primeNumberVec[primeNumberVec.size() - 1]: floor(sqrt(n / 2));
		int endIdx = floor(sqrt(n));
		int jj = 0;
		int kk = 0;
		vector<bool> primeVec(n+1, true);
		for (int ii = 2; ii <= endIdx; ++ii)
		{
			if (primeVec[ii] == true)
			{
				kk = 0;
				jj = pow(ii, 2);
				while (jj <= n)
				{
					primeVec[jj] = false;
					++kk;
					jj += (kk * ii);
				}
			}
			if (primeVec[n] == true)
			{
				return false;
			}
		}
		return true;
	}

	int primePalindrome(int N) {

		bool palindromeFlag;
		bool primeFlag;


		for (int ii = N; ii < 2147483648; ++ii)
		{
			primeFlag = CheckPrime(ii);
			if (primeFlag == true)
			{
				palindromeFlag = CheckPalindrome(ii);
				if (palindromeFlag == true)
				{
					return ii;
				}
			}
		}
		return -1;
	}
	int countPrimes(int n) {

		if (n < 1000)
		{
			int endIdx = n / 2;
		}
		else
		{
			int endIdx = floor(sqrt(n));
		}
		int endIdx = n / 2;
		int jj = 0;
		int kk = 0;
		int ans = 0;
		vector<bool> primeVec(n + 1, true);
		primeVec[0] = false;
		primeVec[1] = false;
		for (int ii = 2; ii <= endIdx; ++ii)
		{
			if (primeVec[ii] == true)
			{
				kk = 0;
				jj = pow(ii, 2) + kk * ii;
				while (jj <= n)
				{
					cout << "ii: \t" << ii << "\tjj: \t" << jj << "\tkk: \t" << kk << endl;
					primeVec[jj] = false;
					++kk;
					jj = pow(ii, 2) + kk * ii;
					// jj += (kk * ii);
				}
			}
		}
		for (int ii = 0; ii < n + 1; ++ii)
		{
			if (primeVec[ii] == true)
			{
				++ans;
				// cout << ii << endl;
			}
		}

		return ans;
	}
};
int main()
{
	Solution S;
	int x = S.countPrimes(500000);
	cout << x << endl;
    return 0;
}

