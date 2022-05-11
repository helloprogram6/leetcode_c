// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/

#include <iostream>
#include <vector>

using namespace std;
int maxProfit(vector<int>& prices) {
	int buyMin = prices[0], buyMax = prices[0], res = 0, sum = 0;
	for (int i = 1; i < prices.size(); i++) {
		if (prices[i] >= buyMax) {
			res = prices[i] - buyMin;
			buyMax = prices[i];
		} else {
			sum += res;
			buyMax = buyMin = prices[i];
			res = 0;
		}
	}
	return sum + res;
}
int main() {
	vector<int> cost;
	cost = vector<int>{7, 1, 5, 3, 6, 4}; // 7
	cout << "f " << maxProfit(cost) << endl;
	cost = vector<int>{1, 2, 3, 4, 5}; // 4
	cout << "f " << maxProfit(cost) << endl;
	cost = vector<int>{7, 6, 4, 3, 1}; // 0
	cout << "f " << maxProfit(cost) << endl;
    cost = vector<int>{1, 3, 6, 6, 8, 1}; // 0
	cout << "f " << maxProfit(cost) << endl;
	return 0;
}
