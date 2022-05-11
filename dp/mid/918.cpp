// https://leetcode.cn/problems/maximum-sum-circular-subarray
#include <iostream>
#include <vector>

using namespace std;
int maxSubarraySumCircular(vector<int> &nums)
{
    int n = nums.size();
    int maxPre = 0, minPre = 0, maxRes = nums[0], minRes = nums[0];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        //单区间 求最大值
        maxPre = max(maxPre + nums[i], nums[i]);
        maxRes = max(maxPre, maxRes);
        //双区间 求最小值
        minPre = min(minPre + nums[i], nums[i]);
        minRes = min(minPre, minRes);
        sum += nums[i];
    }
    //边界情况：数组全为负数
    if (maxRes < 0)
    {
        return maxRes;
    }
    return max(maxRes, sum - minRes);
}
int main()
{
    vector<int> cost;
    cost = vector<int>{-1, -2, -3, -2};
    cout << "f " << maxSubarraySumCircular(cost) << endl;
    cost = vector<int>{1, -2, 3, -2};
    cout << "f " << maxSubarraySumCircular(cost) << endl;
    cost = vector<int>{5, -3, 5};
    cout << "f " << maxSubarraySumCircular(cost) << endl;
    cost = vector<int>{3, -2, 2, -3};
    cout << "f " << maxSubarraySumCircular(cost) << endl;
    cost = vector<int>{5, 4, -1, 7, 8};
    cout << "f " << maxSubarraySumCircular(cost) << endl;
    cost = vector<int>(1000, 50);
    cout << "f " << maxSubarraySumCircular(cost) << endl;
    return 0;
}
