// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

#include <iostream>
#include <vector>

using namespace std;
int maxProfit(vector<int>& prices) {
    //dp0:第i天持有 dp1:第i天不持有且卖了股票 dp2:第i天不持有且没卖股票
	int dp0 = -prices[0], dp1 = 0, dp2 = 0, res;
	for (int i = 1; i < prices.size(); i++) {
		int temp = max(dp2 - prices[i], dp0);
		dp2 = max(dp2, dp1);
		dp1 = prices[i] + dp0;
		dp0 = temp;
	}
	return max(dp2, dp1);
}
int main() {
	vector<int> cost;
	cost = vector<int>{7, 1, 5, 3, 6, 4}; // 5
	cout << "f " << maxProfit(cost) << endl;
	cost = vector<int>{1, 2, 3, 4, 5}; // 4
	cout << "f " << maxProfit(cost) << endl;
	cost = vector<int>{7, 6, 4, 3, 1}; // 0
	cout << "f " << maxProfit(cost) << endl;
	cost = vector<int>{1, 3, 6, 6, 8, 1}; // 7
	cout << "f " << maxProfit(cost) << endl;
	cost = vector<int>{1, 2, 3, 0, 2}; // 3
	cout << "f " << maxProfit(cost) << endl;
	cost = vector<int>{1}; // 0
	cout << "f " << maxProfit(cost) << endl;
	return 0;
}
