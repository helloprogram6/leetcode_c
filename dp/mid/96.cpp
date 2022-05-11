// https://leetcode-cn.com/problems/unique-binary-search-trees/
#include <iostream>
#include <vector>

using namespace std;
int numTrees(int n) {
	vector<int> dp(n + 1, 1);
	dp[0] = dp[1] = 1;
	for (int i = 2; i < n + 1; i++)
	{
		int sum = 0;
		for (int j = 0; j < i; j++)
		{
			sum += dp[j]*dp[i-j-1];
		}
		dp[i] = sum;
	}
	return dp[n];
}
int main(){
	int n;
	n = 1;
	cout << "n:" << n << "\t" << numTrees(n) << endl;
	n = 2;
	cout << "n:" << n << "\t" << numTrees(n) << endl;
	n = 4;
	cout << "n:" << n << "\t" << numTrees(n) << endl;
	n = 5;
	cout << "n:" << n << "\t" << numTrees(n) << endl;
	n = 19;
	cout << "n:" << n << "\t" << numTrees(n) << endl;
	return 0;
}
