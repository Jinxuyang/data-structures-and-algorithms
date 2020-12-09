#include <stdio.h>
int x[100000];
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	int i, j, min;
	for (i = 0; i < n; i++)
		scanf("%d", &x[i]);

	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++) {
			if (x[min] > x[j]) min = j;
		}
		if (min != i) {
			int temp;
			temp = x[min];
			x[min] = x[i];
			x[i] = temp;
		}
	}
	for (i = n - 1; i >= 0; i--) {
		if (i == n - )
			printf("%d", x[i]);
		else
			printf(" %d", x[i]);
	}
	return 0;
}