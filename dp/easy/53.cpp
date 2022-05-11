//https://leetcode-cn.com/problems/maximum-subarray/
#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int> &nums)
{
    int maxRes = INT_MIN, tempRes = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        tempRes += nums[i];
        maxRes = max(maxRes, tempRes);
        if (tempRes <= 0)
        {
            tempRes = 0;
        }
    }
    return maxRes;
}
int main()
{
    vector<int> cost;
    cost = vector<int>{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "f " << maxSubArray(cost) << endl;
    cost = vector<int>{1};
    cout << "f " << maxSubArray(cost) << endl;
    cost = vector<int>{-1};
    cout << "f " << maxSubArray(cost) << endl;
    cost = vector<int>{5, 4, -1, 7, 8};
    cout << "f " << maxSubArray(cost) << endl;
    return 0;
}
