// https://leetcode-cn.com/problems/maximum-length-of-subarray-with-positive-product/
#include <iostream>
#include <vector>

using namespace std;
int getMaxLen(vector<int> &nums)
{
    int dpPos = 0, dpNeg = 0, Res = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] < 0)
        {
            int tempPos = dpNeg ? dpNeg + 1 : 0;
            dpNeg = dpPos + 1;
            dpPos = tempPos;
        }
        else if (nums[i] > 0)
        {
            dpPos++;
            dpNeg = dpNeg ? dpNeg + 1 : 0;
        }
        else
        {
            dpPos = 0, dpNeg = 0;
        }
        Res = max(Res, dpPos);
    }
    return Res;
}
int main()
{
    vector<int> cost;
    cost = vector<int>{1, -2, -3, 4}; // 4
    cout << "f " << getMaxLen(cost) << endl;
    cost = vector<int>{0, 1, -2, -3, -4}; // 3
    cout << "f " << getMaxLen(cost) << endl;
    cost = vector<int>{-1, -2, -3, 0, 1}; // 2
    cout << "f " << getMaxLen(cost) << endl;
    cost = vector<int>{3, -2, 2, -3}; // 4
    cout << "f " << getMaxLen(cost) << endl;
    cost = vector<int>{-1, -2, -9, -6}; // 4
    cout << "f " << getMaxLen(cost) << endl;
    cost = vector<int>{1, 2, 3, 5, -6, 4, 0, 10}; // 4
    cout << "f " << getMaxLen(cost) << endl;
    cost = vector<int>(0, 50); // 0
    cout << "f " << getMaxLen(cost) << endl;
    return 0;
}