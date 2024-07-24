#include <stdio.h>

// Definition for singly-linked list.
struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode *detectCycle(struct ListNode *head)
{
	if (head == NULL || head->next == NULL) return NULL;

	struct ListNode *fast = head, *slow = head;

	do {
		fast = fast->next->next;
		slow = slow->next;
	} while (fast != NULL && fast->next != NULL && fast != slow);

	if (fast != NULL && fast->next != NULL) {
		fast = head;
	} else {
		return NULL;
	}

	while (fast != slow) {
		fast = fast->next;
		slow = slow->next;
	}

	return slow;
}
