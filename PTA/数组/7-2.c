#include <stdio.h>
int a[15];
void swap(int x, int y) {
	int temp = a[x];
	a[x] = a[y];
	a[y] = temp;
}
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	int i, j, max, min;
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	min = 0;
	max = 0;
	for (int j = 1; j < n; j++) {
		if (a[min] > a[j]) min = j;
	}
	swap(min, 0);
	for (int j = 1; j < n; j++) {
		if (a[max] < a[j]) max = j;
	}
	swap(max, n - 1);

	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	return 0;
}