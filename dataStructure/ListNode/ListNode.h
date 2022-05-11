#include <iostream>
#include <vector>

using namespace std;
// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode(): val(0), next(nullptr) {}
	ListNode(int x): val(x), next(nullptr) {}
	ListNode(int x, ListNode* next): val(x), next(next) {}
};
ListNode* createListNode(vector<int>& nums, bool null_head = false) {
	ListNode* head = new ListNode();
	ListNode* temp = head;
	for (int i = 0; i < nums.size(); i++) {
		temp->next = new ListNode(nums[i]);
		temp = temp->next;
	}
	if (null_head) {
		return head;
	} else {
		return head->next;
	}
}
void printListNode(ListNode* head) {
	ListNode* temp = head;
	while (temp) {
		cout << temp->val << " ";
		temp = temp->next;
	}
	cout << endl;
}