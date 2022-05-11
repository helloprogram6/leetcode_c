// https://leetcode-cn.com/problems/best-sightseeing-pair/

#include <iostream>
#include <vector>

using namespace std;
int maxScoreSightseeingPair(vector<int> &values)
{
    int vi = values[0], res = values[0];
    for (int i = 1; i < values.size(); i++)
    {
        res = max(res, vi + values[i] - i);
        vi = max(vi, values[i] + i);
    }
    return res;
}
int main()
{
    vector<int> cost;
    cost = vector<int>{8, 1, 5, 2, 6}; // 11
    cout << "f " << maxScoreSightseeingPair(cost) << endl;
    cost = vector<int>{1, 2}; // 2
    cout << "f " << maxScoreSightseeingPair(cost) << endl;
    return 0;
}
