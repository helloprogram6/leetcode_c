// https://leetcode-cn.com/problems/minimum-falling-path-sum/
#include "../../debug.h"
#include <iostream>
#include <vector>
using namespace std;
int minFallingPathSum(vector<vector<int>>& matrix) {
	int n = matrix.size();
	vector<int> dp(n);
	for (int i = 0; i < n; i++) {
		dp[i] = matrix[0][i];
	}
	int pre;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int temp = dp[j];
			if (j == 0) {
				dp[j] = matrix[i][j] + min(dp[j], dp[j + 1]);
			} else if (j == n - 1) {
				dp[j] = matrix[i][j] + min(pre, dp[j]);
			} else {
				dp[j] = matrix[i][j] + min(pre, min(dp[j], dp[j + 1]));
			}
			pre = temp;
		}
	}
	int res = dp[0];
	for (int i = 1; i < n; i++) {
		res = min(res, dp[i]);
	}
	return res;
}
int main() {
	vector<vector<int>> matrix;
	matrix = vector<vector<int>>{
	    vector<int>{2, 1, 3},
	    vector<int>{6, 5, 4},
	    vector<int>{7, 8, 9},
	};
	cout << minFallingPathSum(matrix) << endl;
	matrix = vector<vector<int>>{vector<int>{-19, 57}, vector<int>{-40, -5}};
	cout << minFallingPathSum(matrix) << endl;
	return 0;
}
