// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/

#include <iostream>
#include <vector>

using namespace std;
int maxProfit(vector<int>& prices) {
	int buy = prices[0], res = 0;
	for (int i = 1; i < prices.size(); i++) {
		res = max(res, prices[i] - buy);
		buy = min(buy, prices[i]);
	}
	return res;
}
int main() {
	vector<int> cost;
	cost = vector<int>{7, 1, 5, 3, 6, 4}; // 6
	cout << "f " << maxProfit(cost) << endl;
	cost = vector<int>{7, 6, 4, 3, 1}; // 0
	cout << "f " << maxProfit(cost) << endl;
	return 0;
}
