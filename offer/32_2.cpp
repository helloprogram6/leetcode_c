/*
@Author: H-zhir
@Date: 2022-05-12 18:42:08
@Description: https://leetcode.cn/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof/
*/
#include "../tree.h"
#include "../debug.h"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> levelOrder(TreeNode* root) {
	vector<vector<int>> res;
	queue<TreeNode*> q;
	if (root){
		q.push(root);
	}
	while(!q.empty()){
		int len = q.size();
		vector<int> temp = vector<int>{};
		while(len--){
			if (q.front()->left){
				q.push(q.front()->left);
			}
			if (q.front()->right){
				q.push(q.front()->right);
			}
			temp.push_back(q.front()->val);
			q.pop();
		}
		res.push_back(temp);
	}
	return res;
}
int main(){
	vector<int> nums;
	nums = vector<int>{3, 9, 20, -1, -1, 15, 7};
	TreeNode* root = createTree(nums);
	printTwoVector(levelOrder(root));
	return 0;
}
