// https://leetcode-cn.com/problems/matrix-block-sum/
#include "../../debug.h"
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
	int n = mat.size();
	int m = mat[0].size();
	vector<vector<int>> ans(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i > 0) {
				mat[i][j] += mat[i - 1][j];
			}
			if (j > 0) {
				mat[i][j] += mat[i][j - 1];
			}
			if (i > 0 && j > 0) {
				mat[i][j] -= mat[i - 1][j - 1];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int up = max(0, i - k);
			int down = min(n - 1, i + k);
			int l = max(0, j - k);
			int r = min(m - 1, j + k);
			ans[i][j] = mat[down][r];
			if (up > 0) {
				ans[i][j] -= mat[up - 1][r];
			}
			if (l > 0) {
				ans[i][j] -= mat[down][l - 1];
			}
			if (up > 0 && l > 0) {
				ans[i][j] += mat[up - 1][l - 1];
			}
		}
	}
	return ans;
}
int main() {
	vector<vector<int>> matrix;
	matrix = vector<vector<int>>{vector<int>{1, 2, 3}, vector<int>{4, 5, 6},
	                             vector<int>{7, 8, 9}};
	printTwoVector(matrixBlockSum(matrix, 1));
	matrix = vector<vector<int>>{vector<int>{1, 2, 3}, vector<int>{4, 5, 6},
	                             vector<int>{7, 8, 9}};
	printTwoVector(matrixBlockSum(matrix, 2));
	return 0;
}
