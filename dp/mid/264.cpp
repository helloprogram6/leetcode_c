// https://leetcode-cn.com/problems/ugly-number-ii/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int nthUglyNumber1(int n) {
	//用三个队列模拟优先队列；用long防止整数溢出
	queue<long> q2, q3, q5;
	int res = 1;
	q2.push(2);
	q3.push(3);
	q5.push(5);
	n--;
	while (n--) {
		int temp2 = q2.front();
		int temp3 = q3.front();
		int temp5 = q5.front();
		int minRes = min(temp2, temp3);
		minRes = min(minRes, temp5);
		if (minRes == temp2) {
			q2.pop();
		} else if (minRes == temp3) {
			q3.pop();
		} else {
			q5.pop();
		}
		if (res != minRes) {
			q2.push(minRes * 2);
			q3.push(minRes * 3);
			q5.push(minRes * 5);
			res = minRes;
		} else {
			n++;
		}
		// cout << "n:" << n << "\t" << minRes << "\t" << res  << endl;
	}
	return res;
}

//动态规划 三指针
int nthUglyNumber(int n) {
	vector<int> dp(n);
	int p2 = 0, p3 = 0, p5 = 0;
	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		int num2 = dp[p2] * 2;
		int num3 = dp[p3] * 3;
		int num5 = dp[p5] * 5;
		dp[i] = min(min(num2, num3), num5);
		if (dp[i] == num2) {
			p2++;
		}
		if (dp[i] == num3) {
			p3++;
		}
		if (dp[i] == num5) {
			p5++;
		}
	}
	return dp[n-1];
}
int main() {
	int n;
	n = 10;
	cout << "n:" << n << "\t" << nthUglyNumber(n) << endl;
	n = 1407; // 536870912
	cout << "n:" << n << "\t" << nthUglyNumber(n) << endl;
	n = 1690; // 2123366400
	cout << "n:" << n << "\t" << nthUglyNumber(n) << endl;
	return 0;
}
