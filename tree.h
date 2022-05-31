/*
@Author: H-zhir
@Date: 2022-05-12 14:15:03
@Description:二叉树相关定义
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x)
	    : val(x)
	    , left(nullptr)
	    , right(nullptr) {}
};
TreeNode* createTree(vector<int>& nums, int i= 0) {
	if (i >= nums.size() || nums[i] == -1)
		return nullptr;
	TreeNode* t = new TreeNode(nums[i]);
	t->left = createTree(nums, 2 * i + 1);
	t->right = createTree(nums, 2 * i + 2);
	return t;
}

//先序遍历
void prePrintTree(TreeNode* root) {
	if (root == nullptr) {
		cout << " #";
		return;
	}
	cout << " " << root->val;
	prePrintTree(root->left);
	prePrintTree(root->right);
}

//层次遍历 用队列
void levelPrintTree(TreeNode* root) {
	queue<TreeNode*> q, t;
	if (root == nullptr) {
		return;
	}
	q.push(root);
	while (!q.empty()) {
		while (!q.empty()) {
			TreeNode* top = q.front();
			q.pop();
			cout << top->val << " ";
			if (top->left) {
				t.push(top->left);
			}
			if (top->right) {
				t.push(top->right);
			}
		}
		while (!t.empty()) {
			q.push(t.front());
			t.pop();
		}
		cout << endl;
	}
}