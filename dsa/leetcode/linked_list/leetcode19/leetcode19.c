#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
	// create a dummy node to solve edge problem (when list size = 1)
	struct ListNode dummy_node = { 0, head };
	struct ListNode *remove_ptr = &dummy_node;
	struct ListNode *edge_ptr = &dummy_node;

	// setting edge
	for (int i = 0; i < n; i++) {
		edge_ptr = edge_ptr->next;
	}

	// starting move
	while (edge_ptr->next != NULL) {
		remove_ptr = remove_ptr->next;
		edge_ptr = edge_ptr->next;
	}

	// delete
	struct ListNode *free_target = remove_ptr->next;
	remove_ptr->next = remove_ptr->next->next;
	free(free_target);

	return dummy_node.next;
}
