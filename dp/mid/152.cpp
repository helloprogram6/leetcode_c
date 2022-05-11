//https://leetcode-cn.com/problems/maximum-product-subarray
#include <iostream>
#include <vector>

using namespace std;
int maxProduct(vector<int> &nums)
{
    int maxPre = 1, maxRes = nums[0], minPre = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] < 0)
        {
            int temp = max(minPre * nums[i], nums[i]);
            minPre = min(maxPre * nums[i], nums[i]);
            maxPre = temp;
        }
        else
        {
            maxPre = max(maxPre * nums[i], nums[i]);
            minPre = min(minPre * nums[i], nums[i]);
        }
        maxRes = max(maxRes, maxPre);
    }
    return maxRes;
}
int main()
{
    vector<int> cost;
    cost = vector<int>{2, 3, -2, 4};//6
    cout << "f " << maxProduct(cost) << endl;
    cost = vector<int>{-2, 0, -1};//0
    cout << "f " << maxProduct(cost) << endl;
    cost = vector<int>{-2, 3, -4};//24
    cout << "f " << maxProduct(cost) << endl;
    cost = vector<int>{3, -2, 2, -3};//36
    cout << "f " << maxProduct(cost) << endl;
    cost = vector<int>{-1, -2, -9, -6};//108
    cout << "f " << maxProduct(cost) << endl;
    cost = vector<int>(1000, 50);
    cout << "f " << maxProduct(cost) << endl;
    return 0;
}
