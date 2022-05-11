// https://leetcode-cn.com/problems/pascals-triangle-ii/
#include <iostream>
#include <vector>

using namespace std;
vector<int> getRow(int rowIndex) {
	vector<int> Res(rowIndex + 1, 1);
	for (int i = 2; i < rowIndex + 1; i++) {
		for (int j = i - 1; j > 0; j--) {
			Res[j] += Res[j - 1];
		}
	}
	return Res;
}
void printV(vector<int> Res) {
	for (int i = 0; i < Res.size(); i++) {
		cout << Res[i] << " ";
	}
	cout << endl;
}
int main() {
	int n;
	n = 2;
	cout << "n:" << n << "\t" << endl;
	printV(getRow(n));
	n = 3;
	cout << "n:" << n << "\t" << endl;
	printV(getRow(n));
	n = 10;
	cout << "n:" << n << "\t" << endl;
	printV(getRow(n));
	return 0;
}