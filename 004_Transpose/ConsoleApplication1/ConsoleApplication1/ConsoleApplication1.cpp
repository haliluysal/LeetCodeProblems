// ConsoleApplication1.cpp: Konsol uygulamasının giriş noktasını tanımlar.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
	void coutMtx(vector<vector<int>>& A)
	{
		int row = A.size();
		int col = A[0].size();
		for (int ii = 0; ii < row; ++ii)
		{
		for (int jj = 0; jj < col; ++jj)
		{
		cout << A[ii][jj] << "\t";
		}
		cout << endl;
		}
		cout << endl << endl << endl;
	}
	vector<vector<int>> transpose(vector<vector<int>>& A) {
		int row = A.size();
		int col = A[0].size();
		vector<vector<int>> result(col, vector<int>(row));
		if (row <= col)
		{
			coutMtx(A);
			// STEP 1: swap off diagonal elements
			for (int ii = 0; ii < row; ++ii)
			{
				for (int jj = ii; jj < row; ++jj)
				{
					result[ii][jj] = A[jj][ii];
					result[jj][ii] = A[ii][jj];
				}
			}
			// coutMtx(A);
			// coutMtx(result);
			for (int ii = row; ii < col; ++ii)
			{
				for (int jj = 0; jj < row; ++jj)
				{
					result[ii][jj] = A[jj][ii];
				}
			}
		}
		else
		{
			for (int ii = 0; ii < col; ++ii)
			{
				for (int jj = ii; jj < col; ++jj)
				{
					result[ii][jj] = A[jj][ii];
					result[jj][ii] = A[ii][jj];
				}
			}
			// coutMtx(A);
			// coutMtx(result);
			for (int ii = col; ii < row; ++ii)
			{
				for (int jj = 0; jj < col; ++jj)
				{
					result[jj][ii] = A[ii][jj];
				}
			}
		}
		// coutMtx(result);
		return result;
	}
};


int main()
{
	Solution S;
	vector<vector<int>> x{ { 1, 2, 3, 4},{ 5, 6, 7, 8 },{ 9, 10, 11, 12}, {13, 14, 15, 16 }, {17, 18, 19, 20} };
	x = S.transpose(x);
    return 0;
}

