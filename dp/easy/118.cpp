// https://leetcode-cn.com/problems/pascals-triangle/
#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> generate(int numRows) {
	vector<vector<int>> Res(numRows);
	for (int i = 0; i < numRows; i++) {
		vector<int> vtemp(i + 1, 1);
		for (int j = 1; j < i; j++) {
			vtemp[j] = Res[i - 1][j] + Res[i - 1][j - 1];
		}
		Res[i] = vtemp;
	}
	return Res;
}
void printV(vector<vector<int>> Res) {
	for (int i = 0; i < Res.size(); i++) {
		for (int j = 0; j < Res[i].size(); j++) {
			cout << Res[i][j] << " ";
		}
		cout << endl;
	}
}
int main() {
	int n;
	n = 5;
	cout << "n:" << n << "\t" << endl;
	printV(generate(n));
	n = 5;
	cout << "n:" << n << "\t" << endl;
	printV(generate(n));
	n = 10;
	cout << "n:" << n << "\t" << endl;
	printV(generate(n));
	return 0;
}
