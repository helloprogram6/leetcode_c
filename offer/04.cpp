/*
@Author: H-zhir
@Date: 2022-05-11 16:27:05
@Description: https://leetcode.cn/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/
*/

#include <iostream>
#include <vector>
using namespace std;

bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
	int n = matrix.size();
	if (n == 0)
		return false;
	int m = matrix[0].size();
	int i = 0, j = m - 1;
	while (i < n && j >= 0) {
		if (matrix[i][j] == target) {
			return true;
		} else if (matrix[i][j] > target) {
			j--;
		} else {
			i++;
		}
	}
	return false;
}
int main() {
	vector<vector<int>> matrix;
	matrix = vector<vector<int>>{
	    vector<int>{1, 4, 7, 11, 15},    vector<int>{2, 5, 8, 12, 19},
	    vector<int>{3, 6, 9, 16, 22},    vector<int>{10, 13, 14, 17, 24},
	    vector<int>{18, 21, 23, 26, 30},
	};
	cout << findNumberIn2DArray(matrix, 5) << endl;
	cout << findNumberIn2DArray(matrix, 20) << endl;
	matrix = vector<vector<int>>{
	};
	cout << findNumberIn2DArray(matrix, 20) << endl;
	matrix = vector<vector<int>>{
	    vector<int>{},
	};
	cout << findNumberIn2DArray(matrix, 20) << endl;
	matrix = vector<vector<int>>{
	    vector<int>{-5},
	};
	cout << findNumberIn2DArray(matrix, -5) << endl;
	return 0;
}
