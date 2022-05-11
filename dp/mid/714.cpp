//https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
#include <iostream>
#include <vector>

using namespace std;
int maxProfit(vector<int>& prices, int fee) {
    int dp0 = -prices[0], dp1 = 0;
    for (int i = 0; i < prices.size(); i++)
    {
        int temp = max(dp1 - prices[i], dp0);
        dp1 = max(dp0 + prices[i] - fee, dp1);
        dp0 = temp;
    }
    return dp1;
}
int main(){
	vector<int> cost;
	cost = vector<int>{1, 3, 2, 8, 4, 9}; // 8
	cout << "f " << maxProfit(cost, 2) << endl;
	cost = vector<int>{1,3,7,5,10,3}; // 6
	cout << "f " << maxProfit(cost, 3) << endl;
	return 0;
}
