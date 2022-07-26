#include <stdio.h>

int main(int argc, char const *argv[])
{
	char c;
	int cnt = 0;
	while (c != EOF) {
		c = getchar();
		if (c == '(')
			cnt ++;
		if (c == ')')
			cnt --;
		if (cnt < 0) {
			printf("\nfalse\n");
			return 0;
		}
	}
	if (cnt != 0) {
		printf("\nfalse\n");
		return 0;
	}
	printf("\ntrue\n");
	return 0;
}
