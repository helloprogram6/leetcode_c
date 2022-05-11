/*
@Author: H-zhir
@Date: 2022-05-11 15:20:20
@Description: https://leetcode.cn/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/
*/
#include "../debug.h"
#include <iostream>
#include <map>
#include <vector>
using namespace std;
int findRepeatNumber(vector<int>& nums) {
	int i = 0;
	while (i < nums.size()) {
		if (nums[i] == i) {
			i++;
			continue;
		}
		if (nums[i] == nums[nums[i]]) {
			return nums[i];
		}
		int temp = nums[nums[i]];
		nums[nums[i]] = nums[i];
		nums[i] = temp;
	}
	return -1;
}

int main() {
	vector<int> nums;
	nums = vector<int>{2, 3, 1, 0, 2, 5, 3};
	cout << findRepeatNumber(nums) << endl;
	nums = vector<int>{3, 4, 2, 0, 0, 1};
	cout << findRepeatNumber(nums) << endl;
	return 0;
}
