#include <stdio.h>
int main(int argc, char const *argv[])
{
	int n, x[15], a[15];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &x[i]);
	for (int i = 0; i < n; i ++) {
		a[i] = x[i + 1] - x[i];

	}
	int cnt = 1;
	for (int i = 0; i < n - 1; i++) {
		if (cnt == 3) {
			printf("%d\n", a[i]);
			cnt = 0;
		}
		else {
			if (i == n - 2) printf("%d", a[i]);
			else printf("%d ", a[i]);
		}

		cnt++;
	}
	return 0;
}