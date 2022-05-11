// https://leetcode-cn.com/problems/triangle/
#include <iostream>
#include <vector>

using namespace std;
int minimumTotal(vector<vector<int>>& triangle) {
	int n = triangle.size();
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < triangle[i].size(); j++) {
			if (j == 0) {
				triangle[i][j] += triangle[i - 1][j];
			} else if (j == triangle[i].size() - 1) {
				triangle[i][j] += triangle[i - 1][j - 1];
			} else {
				triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
			}
		}
	}
	int res = triangle[n - 1][0];
	for (int j = 0; j < triangle[n - 1].size(); j++) {
		res = min(res, triangle[n - 1][j]);
	}
	return res;
}
int main() {
	vector<vector<int>> matrix;
	matrix = vector<vector<int>>{vector<int>{2}, vector<int>{3, 4},
	                             vector<int>{6, 5, 7}, vector<int>{4, 1, 8, 3}};
	cout << minimumTotal(matrix) << endl;
	matrix = vector<vector<int>>{vector<int>{-10}};
	cout << minimumTotal(matrix) << endl;
	return 0;
}
