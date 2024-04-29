#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

unsigned int getNext(unsigned int n)
{
	unsigned int result = 0;

	while (n != 0) {
		int temp = 0;
		temp += n % 10;
		result += temp * temp;
		n /= 10;
	}

	return result;
}

bool isHappy(unsigned int n)
{
	unsigned fast = n, slow = n;

	while (fast != 1 && getNext(fast) != 1) {
		fast = getNext(getNext(fast));
		slow = getNext(slow);

		if (fast == slow) return false;
	}

	return true;
}

int main()
{
	srand(time(0));
	#define TEST_OP 20
	for (int i = 0, test_val; i < TEST_OP; i++) {
		test_val = rand() % 101;
		printf("value: %d %d\n", test_val, isHappy(test_val));
	}
	return 0;
}
