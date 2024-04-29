// leetcode 141
bool hasCycle(Node *head)
{
	if (head == NULL) return false;

	Node *p_fast = head, *p_slow = head;

	while(p_fast && p_fast->next) {
		p_fast = p_fast->next->next;
		p_slow = p_slow->next;
		if (p_fast == p_slow) return true;
	}

	return false;
}
