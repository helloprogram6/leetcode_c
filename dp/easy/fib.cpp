// https://leetcode-cn.com/problems/fibonacci-number/
#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution
{
public:
    int fib1(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        for (int i = 2; i < dp.size(); i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n - 1];
    }
    int fib(int n)
    {
        if (n < 2)
        {
            return n;
        }
        int a = 0, b = 1;
        int temp;
        for (int i = 1; i < n; i++)
        {
            temp = b;
            b = a + b;
            a = temp;
        }
        return b;
    }
};
int main()
{
    int n;
    Solution s;
    n = 1;
    cout << "n:" << n << " fib(n):" << s.fib(n) << endl;
    n = 2;
    cout << "n:" << n << " fib(n):" << s.fib(n) << endl;
    n = 3;
    cout << "n:" << n << " fib(n):" << s.fib(n) << endl;
    n = 4;
    cout << "n:" << n << " fib(n):" << s.fib(n) << endl;
    n = 5;
    cout << "n:" << n << " fib(n):" << s.fib(n) << endl;
}
