#include <stdio.h>
// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// solution 1
unsigned int getListLen(struct ListNode *head)
{
	if (head == NULL) return 0;
	unsigned int counter = 1;

	while(head->next != NULL) {
		head = head->next;
		counter++;
	}

	return counter;
}

struct ListNode* rotateRight(struct ListNode* head, int k)
{
	struct ListNode *p = head, *q = head;

	// 這裡是檢測 list 的長度為 0, list 為空指針, k 等於 0 的時侯返回給到的 head
	if (head == NULL || head->next == NULL || k == 0) return head;

	// 因為拿到的 k 可能數字很大所以我們要先拿到 list 的長度再直接求 p 和 q 之間的長度
	// 0 <= k <= 2 * 109
	for (int i = 0; i < k % getListLen(head); i++) {
		q = q->next;
	}
	// 而不是像以下的代碼一樣打算在遍歷的時侯決定 p 和 q 之間的長度, 因為在 k 的數字很大的時侯, 循環的次數會很多
	// 這正是我第一次沒去看 Constraints, 也沒考慮這部分會影響這麼多, 而寫的代碼, 做題是真有用呀
	// for (int i = 0; i < k; i++) {
	// 	if (q->next == NULL) {
	// 		q = head;
    //         if (k - i == 1) {
    //             return head;
    //         }
    //         continue;
	// 	}
	// 	q = q->next;
	// }

	if (q == NULL) return head;

	while (q->next != NULL) {
		p = p->next;
		q = q->next;
	}

	struct ListNode *new_head = p->next;
	p->next = NULL;
	q->next = head;

	return new_head;
}

// solution 2
struct ListNode* rotateRight(struct ListNode* head, int k)
{
	// 這裡是檢測 list 的長度為 0, list 為空指針, k 等於 0 的時侯返回給到的 head
	if (head == NULL || head->next == NULL || k == 0) return head;

	unsigned int list_len = getListLen(head);

	struct ListNode *p = head;
	struct ListNode *new_head = NULL;

	unsigned int new_head_pos = list_len - (k % list_len);

	for (int i = 1; i < list_len; i++) {
		if (i == new_head_pos) {
			new_head = p->next;
			p->next = NULL;
		}
		if (p->next == NULL) {
			p->next = head;
		}
		p = p->next;
	}

	return new_head;
}
