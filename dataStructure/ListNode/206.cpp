// https://leetcode-cn.com/problems/reverse-linked-list/

#include "ListNode.h"
#include <iostream>
#include <vector>

using namespace std;
ListNode* reverseList(ListNode* head) {
    ListNode* last = head;
    ListNode* temp = new ListNode();
    head = temp;
    while(last){
        temp = last;
        last = temp->next;
        temp->next = head->next;
        head->next = temp;
    }
    return head->next;
}
int main() {
	vector<int> nums;
    nums = vector<int>{1, 2, 3, 4, 5};
	ListNode* head = createListNode(nums);
    printListNode(head);
	printListNode(reverseList(head));
	// head = createListNode(vector<int>{1, 2});
	// printListNode(reverseList(head));
	// head = createListNode(vector<int>{});
	// printListNode(reverseList(head));
	return 0;
}
