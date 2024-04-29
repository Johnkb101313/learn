// leetcode 206
Node* reverseList(NodeList* list) {
	Node *p = list->head;
	Node *new_next = NULL;
	Node *next_node;

	while(1) {
		next_node = p->next;
		p->next = new_next;
		new_next = p;
		if (next_node == NULL) break;
		p = next_node;
	}
	list->head = p;
	return p;
}

// recursive
Node *reverse_list(Node *node, Node *last_node)
{
	if (node == NULL) return last_node;
	Node *head = reverse_list(node->next, node);
	node->next = last_node;
	return head;
}

void reverseList_r(NodeList *list)
{
	list->head = reverse_list(list->head, NULL);
}
// end leetcode 206
