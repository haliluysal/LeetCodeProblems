// ConsoleApplication1.cpp: Konsol uygulamasının giriş noktasını tanımlar.
//

#include "stdafx.h"
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
	int profit = 0;
	int dummyDiff = -32536;
	for (int ii = 0; ii < prices.size() - 1; ii++) {
		for (int jj = ii + 1; jj < prices.size(); jj++) {
			if (dummyDiff < prices[jj] - prices[ii]) {
				dummyDiff = prices[jj] - prices[ii];
			}
		}
		if (dummyDiff > 0)
		{
			profit += dummyDiff;
		}
	}

	return profit;
}

int main()
{
	vector<int> x;
	x.push_back(7);
	x.push_back(1);
	x.push_back(5);
	x.push_back(3);
	x.push_back(6);
	x.push_back(4);
	int n = maxProfit(x);
    return 0;
}

