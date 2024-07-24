#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// leetcode 2
// link: https://leetcode.com/problems/add-two-numbers/description/

// Definition for singly-linked list.
struct ListNode {
	int val;
    struct ListNode *next;
};

// first submission
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
	struct ListNode dummy_node = {0}, *p = &dummy_node;
	int l1val, l2val;
	bool cf = false;

	while ((l1 != NULL || l2 != NULL) || cf == true) {
		if (l1 != NULL) {
			l1val = l1->val;
			l1 = l1->next;
		} else {
			l1val = 0;
		}

		if (l2 != NULL) {
			l2val = l2->val;
			l2 = l2->next;
		} else {
			l2val = 0;
		}

		p->next = calloc(1, sizeof(struct ListNode));
		p = p->next;
		p->val = (l1val + l2val + cf) % 10;

		if (l1val + l2val + cf > 9)
			cf = true;
		else
			cf = false;
	}

	return dummy_node.next;
}

// second submission
int getListLen(struct ListNode *head)
{
	int counter = 1;
	while (head->next != NULL) {
		head = head->next;
		counter++;
	}

	return counter;
}

struct ListNode* addZnode(struct ListNode *head)
{
	while (head->next != NULL) {
		head = head->next;
	}

	struct ListNode *p = calloc(1, sizeof(struct ListNode));
	p->next = p;

	head->next = p;

	return head;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
	unsigned int l1_len = getListLen(l1);
	unsigned int l2_len = getListLen(l2);

	if (l1_len > l2_len) {
		addZnode(l2);
	} else if (l2_len > l1_len) {
		addZnode(l1);
	}

	struct ListNode dummy_node = {0}, *p = &dummy_node;
	bool cf = false;

	while ((l1 != NULL && l2 != NULL)) {
		p->next = calloc(1, sizeof(struct ListNode));
		p = p->next;
		p->val = (l1->val + l2->val + cf) % 10;

		if (l1->val + l2->val + cf > 9) {
			cf = true;
		} else {
			cf = false;
		}

		l1 = l1->next;
		l2 = l2->next;
	}

    if (cf == true) {
        p->next = calloc(1, sizeof(struct ListNode));
		p = p->next;
		p->val = 1;
    }

	return dummy_node.next;
}

// third submission
struct ListNode *f(bool cf, struct ListNode *l1, struct ListNode *l2)
{
	int l1_val = l1 == NULL ? 0 : l1->val;
	int l2_val = l2 == NULL ? 0 : l2->val;
	int value = l1_val + l2_val + cf;

	if (l1 == NULL && l2 == NULL && cf == false) return NULL;

	struct ListNode *next_node = f(value > 9 ? true : false,\
			l1 == NULL ? NULL : l1->next ,\
			l2 == NULL ? NULL : l2->next);

	struct ListNode *new_node = malloc(sizeof(struct ListNode));
	new_node->val = value % 10;
	new_node->next = next_node;

	return new_node;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
	return f(false, l1, l2);
}
