/*
@Author: H-zhir
@Date: 2022-05-12 15:34:13
@Description:
https://leetcode.cn/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof/
*/
#include "../tree.h"
#include "../debug.h"
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> levelOrder(TreeNode* root) {
	vector<int> nums;
	queue<TreeNode*> q;
	if (root != nullptr) {
		q.push(root);
	}
	while (!q.empty()) {
		TreeNode* t = q.front();
		nums.push_back(t->val);
		q.pop();
		if (t->left) {
			q.push(t->left);
		}
		if (t->right) {
			q.push(t->right);
		}
	}
	return nums;
}

int main() {
	vector<int> nums;
	nums = vector<int>{3, 9, 20, -1, -1, 15, 7};
	TreeNode* root = createTree(nums);
	printVector(levelOrder(root));
    return 0;
}