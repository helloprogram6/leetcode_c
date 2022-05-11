// https://leetcode-cn.com/problems/range-sum-query-2d-immutable/
#include "../../debug.h"
#include <iostream>
#include <vector>
using namespace std;
class NumMatrix {
private:
	vector<vector<int>> dp;

public:
	NumMatrix(vector<vector<int>>& matrix) {
		int n = matrix.size();
		int m = matrix[0].size();
		this->dp = vector<vector<int>>(n, vector<int>(m, 0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				this->dp[i][j] = matrix[i][j];
				if (i > 0) {
					this->dp[i][j] += dp[i - 1][j];
				}
				if (j > 0) {
					this->dp[i][j] += dp[i][j - 1];
				}
				if (i > 0 && j > 0) {
					this->dp[i][j] -= dp[i - 1][j - 1];
				}
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		int res = dp[row2][col2];
		if (row1 > 0) {
			res -= dp[row1 - 1][col2];
		}
		if (col1 > 0) {
			res -= dp[row2][col1 - 1];
		}
		if (col1 > 0 && row1 > 0) {
			res += dp[row1 - 1][col1 - 1];
		}
		return res;
	}
};

int main() {
	vector<vector<int>> matrix;
	matrix = vector<vector<int>>{vector<int>{3, 0, 1, 4, 2},
	                             vector<int>{5, 6, 3, 2, 1},
	                             vector<int>{1, 2, 0, 1, 5},
	                             vector<int>{4, 1, 0, 1, 7},
	                             vector<int>{1, 0, 3, 0, 5}};
	NumMatrix* obj = new NumMatrix(matrix);
	cout << obj->sumRegion(2, 1, 4, 3) << endl;
	cout << obj->sumRegion(1, 1, 2, 2) << endl;
	cout << obj->sumRegion(1, 2, 2, 4) << endl;
	return 0;
}
