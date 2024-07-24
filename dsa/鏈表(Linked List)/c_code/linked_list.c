#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define LIST_ERROR_CODE 1
#define LIST_PTR_ERROR_CODE NULL

#define DL 3
#define DIGIT_LEN_PRTFM(n) FM(n)
#define FM(n) "%" #n "d"

#define PRI_SP(n) ({ for (int i = 0; i < n; i++) printf(" "); })


typedef struct Node {
	int data;
	struct Node *next;
} Node;

// 為了方便打印, 所以加多了這個結構
typedef struct NodeList {
	Node *head;
	unsigned int len;
} NodeList;

Node *node_new(int val)
{
	Node *node = calloc(1, sizeof(Node));
	if (node == NULL) {
		perror("calloc");
		return LIST_PTR_ERROR_CODE;
	}
	node->data = val;

	return node;
}

NodeList *list_new(int val)
{
	NodeList *list = malloc(sizeof(NodeList));
	if (list == NULL) {
		perror("malloc");
		return LIST_PTR_ERROR_CODE;
	};

	Node *node = calloc(1, sizeof(Node));
	if (node == NULL) {
		perror("calloc");
		free(list);
		return LIST_PTR_ERROR_CODE;
	}

	if (val != 0) node->data = val;

	list->head = node;
	list->len = 1;

	return list;
}

void nodes_free(Node *node)
{
	if (node->next != NULL) nodes_free(node->next);
	free(node);
	return;
}

void list_free(NodeList *list)
{
	nodes_free(list->head);
	free(list);
	return;
}

void list_print(NodeList *list)
{
	Node *p = list->head;

	for (int i = 0; i < list->len; i++) {
		printf(DIGIT_LEN_PRTFM(DL)"    ", i);
	}
	printf("\n");

	for (int i = 1; i < list->len; i++) {
		printf(DIGIT_LEN_PRTFM(DL)" -> ", p->data);
		p = p->next;
	}
	printf(DIGIT_LEN_PRTFM(DL)"\n", p->data);
	printf("list->len = %u\n", list->len);

	return;
}

// 無頭鏈表的插入操作代碼
// Node *list_insert(NodeList *list, int val, unsigned int pos)
// {
// 	Node *pos_node = list->head;
// 	Node *new_node;
//
// 	new_node = node_new(val);
// 	if (new_node == NULL)
// 		return LIST_ERROR_CODE;
//
// 	if (pos == 0) {
// 		list->head = new_node;
// 		new_node->next = pos_node;
// 		list->len++;
// 		return new_node;
// 	}
//
// 	for (int i = 1; i < pos; i++) {
// 		if (pos_node == NULL) {
// 			free(new_node);
// 			return LIST_ERROR_CODE;
// 		}
// 		pos_node = pos_node->next;
// 	}
//
// 	new_node->next = pos_node->next;
// 	pos_node->next = new_node;
// 	list->len++;
//
// 	return new_node;
// }

// 有頭鏈表的插入操作代碼
Node *list_insert(NodeList *list, int val, unsigned int pos)
{
	Node dummy_node = { 0, list->head }, *p = &dummy_node;
	Node *new_node = node_new(val);
	if (new_node == LIST_PTR_ERROR_CODE) {
		return LIST_PTR_ERROR_CODE;
	}

	for (int i = 0; i < pos; i++) {
		if (p == NULL) {
			free(new_node);
			return LIST_PTR_ERROR_CODE;
		}
		p = p->next;
	}
	new_node->next = p->next;
	p->next = new_node;

	// update NodeList structure status
	list->head = dummy_node.next;
	list->len++;

	return dummy_node.next;
}

int list_search(NodeList* list, int data)
{
	Node *p = list->head;
	for (int i = 0; p != NULL; ++i, p = p->next) {
		if (p->data == data) return i;
	}

	return -1;
}

void list_print_arrow(unsigned int pos)
{
	for (int i = 0; i < pos; i++) {
		PRI_SP(DL);
		printf("    ");
	}
	PRI_SP(DL - 1);
	printf("^\n");
	for (int i = 0; i < pos; i++) {
		PRI_SP(DL);
		printf("    ");
	}
	PRI_SP(DL - 1);
	printf("|\n");
}

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

int main()
{
	srand(time(0));

	// create a new list
	NodeList *list = list_new(20);

	// test code:
	#define TEST_OP 10
	int counter = 1;
	while(counter <= TEST_OP) {
		int val = rand() % 101;
		unsigned int pos = rand() % counter;

		printf("test result %d\n", counter);
		printf("insert %d in %u\n", val, pos);

		if (list_insert(list, val, pos) == LIST_PTR_ERROR_CODE) break;

		list_print(list);
		printf("\n\n\n");

		counter++;
	}

	reverseList_r(list);

	printf("hasCycle = %d\n", hasCycle(list->head));

	list_print(list);

	int usr_in;
	scanf("%d", &usr_in);
	int pos = list_search(list, usr_in);

	if (pos != -1) {
		list_print(list);
		list_print_arrow(pos);
	}

	// free list
	list_free(list);

	return 0;
}
