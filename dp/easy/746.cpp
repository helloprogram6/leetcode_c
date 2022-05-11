// https://leetcode-cn.com/problems/min-cost-climbing-stairs/

#include <iostream>
#include <vector>

using namespace std;
int minCostClimbingStairs1(vector<int> &cost)
{
    vector<int> dp(cost.size(), 0);
    for (int i = 1; i < cost.size(); i++)
    {
        if (i == 1)
        {
            dp[i] = min(cost[1], cost[0]);
        }
        else
        {
            dp[i] = min(cost[i] + dp[i - 1], cost[i - 1] + dp[i - 2]);
        }
        // cout<<"i:"<<i<<"-->"<<dp[i]<<endl;
    }
    return dp[cost.size() - 1];
}
int minCostClimbingStairs(vector<int> &cost)
{
    int a = 0, b = 0, res;
    if (cost.size() < 2)
    {
        return 0;
    }
    res = min(cost[1], cost[0]);
    res = b;
    for (int i = 1; i < cost.size(); i++)
    {
        res = min(cost[i] + b, cost[i - 1] + a);
        a = b;
        b = res;
    }
    return res;
}
int main()
{
    vector<int> cost;
    cost = vector<int>{10, 15, 20};
    cout <<"f"<< minCostClimbingStairs(cost) << endl;
    cost = vector<int>{1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout <<"f"<< minCostClimbingStairs(cost) << endl;
    return 0;
}
