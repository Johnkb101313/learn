#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SL_ERROR_CODE 1

typedef struct {
	int *data;
	unsigned int len;
	unsigned int count;
} Seq_List;

int sl_expand(Seq_List *list)
{
	if (list == NULL) return SL_ERROR_CODE;

	int *p = realloc(list->data, (list->len * 2) * sizeof(int));

	if (p == NULL) {
		perror("realloc");
		return SL_ERROR_CODE;
	} else {
		list->data = p;
		list->len *= 2;
	}
	
	return 0;
}

int sl_insert(Seq_List *list, int ele, unsigned int index)
{
	bool ls_is_full = (list->len == list->count);

	// control index range: list->data[-1 to list->len]
	if ((index > list->count) || index < 0) return 1;
	// if (!ls_is_full && index == list->len) return 1;

	// if sequential list length is full and user want to appent a new element to it, we expand more memory size to it
	if (ls_is_full) {
		printf("expand!!!\n");
		if (sl_expand(list) == SL_ERROR_CODE) return SL_ERROR_CODE;
	}

	for (unsigned int i = list->count - 1; i > index; i--) {
		list->data[i + 1] = list->data[i];
	}
	list->data[index + 1] = list->data[index];

	list->data[index] = ele;
	list->count++;
	return 0;
}

int sl_erase(Seq_List *list, unsigned int index)
{
	if (list->count == 0) return SL_ERROR_CODE;
	if (index >= list->count || index < 0) return SL_ERROR_CODE;

	int rm_ele = list->data[index];
	while (index != list->count - 1) {
		list->data[index] = list->data[index + 1];
		index++;
	}

	list->count--;

	return rm_ele;
}

Seq_List *sl_init(unsigned int len, int init_ele[], unsigned int init_ele_count)
{
	Seq_List *list = calloc(1, sizeof(Seq_List));
	if (list == NULL) {
		perror("calloc");
		return NULL;
	}

	list->data = calloc(len, sizeof(*(list->data)));
	if (list->data == NULL) {
		free(list);
		perror("calloc");
		return NULL;
	}

	for (int i = 0; i < init_ele_count; i++) {
		list->data[i] = init_ele[i];
	}
	list->len = len;
	list->count = init_ele_count;
	return list;
}

void sl_free(Seq_List *list)
{
	free(list->data);
	free(list);
}

void print_ele(Seq_List *list)
{
	int len = 0;

	for (int i = 0; i < list->count; i++) {
		len += printf("%5d", list->data[i]);
	}
	printf("\n");

	for (int i = 0; i < len; i++) {
		printf("-");
	}
	printf("\n");

	for (int i = 0; i < list->count; i++) {
		printf("%5d", i);
	}
	printf("\n");
	printf("len = %u\n", list->len);
	printf("count = %u\n", list->count);
}

void print_sl(Seq_List *list)
{
	int len = 0;
	for (int i = 0; i < list->len; i++)
	{
		len += printf("%5d", list->data[i]);
	}
	printf("\n");

	for (int i = 0; i < len; i++) {
		printf("-");
	}
	printf("\n");
	
	for (int i = 0; i < list->len; i++) {
		printf("%5d", i);
	}
	printf("\n");
	printf("len = %u\n", list->len);
	printf("count = %u\n", list->count);
}

int main()
{
	srand(time(0));

	int arr[] = { 1, 2, 3, 4, 25, 64, 69, 57, 34, 79 };
	Seq_List *list = sl_init(10, arr, 10);

	// test insert operation and erase operation
	#define MAX_OP 20

	for (int i = 0; i < MAX_OP; i++) {
		int test_unit = rand() % 4;
		// 75% do insert operation
		// 25% do erase operation
		switch(test_unit) {
			case 0:
			case 1:
			case 2:
				int index = rand() % 20;
				int value = rand() % 100;
				printf("[INSERT]\n"
					   "ins_index: %u\n"
					   "ins_value: %d\n", index, value);
				sl_insert(list, value, index);
				print_ele(list);
				printf("\n");
				break;
			case 3:
				int rm_index = rand() % 10;
				printf("[ERASE]\n"
					   "rm_index: %u\n", rm_index);
				int rm_ele = sl_erase(list, rm_index);
				print_ele(list);
				printf("rm_ele: %d\n", rm_ele);
				printf("\n");
				break;
		}
	}
	
	sl_free(list);
	return 0;
}
