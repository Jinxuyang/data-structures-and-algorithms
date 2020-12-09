#include<stdio.h>
int main()
{
	int T;
	char x;
	scanf("%d\n", &T);
	while (T--) {
		int i = 0, res = 0, temp = 1;
		while ((x = getchar()) != '\n') {
			if (x == 'O') {
				res += temp;
				temp++;
			}
			else {
				temp = 1;
			}

		}
		printf("%d\n", res);
	}

	return 0;
}