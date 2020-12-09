#include <stdio.h>
int main(int argc, char const *argv[])
{
	int n, temp = 1;
	scanf("%d", &n);
	int i, j;

	for (j = 0; j < n; j++) {
		for (i = 1; i < n - j; i++) {
			printf(" ");
		}
		for (i = 0; i <= j; i++) {
			if (i == 0 || j == 0) {
				temp = 1;
			}

			else {
				temp = temp * (j - i + 1) / i;
			}
			printf("%4d", temp);

		}
		printf("\n");
	}
	return 0;
}