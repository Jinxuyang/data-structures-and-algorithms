#include <stdio.h>
int main(int argc, char const *argv[])
{
	int a[11];
	for (int i = 0; i < 10; i++)
		scanf("%d", &a[i]);
	int T;
	scanf("%d", &T);
	while (T--) {
		int temp;
		scanf("%d", &temp);
		a[temp - 1] += 10;
	}
	for (int i = 0; i < 10; i++) {
		if (i == 0) printf("%d", a[i]);
		else printf(" %d", a[i]);
	}

	return 0;
}