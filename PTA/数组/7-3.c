#include<stdio.h>
int main(int argc, char const *argv[])
{
	int n, x[1010];
	scanf("%d", &n);
	int i;
	for (i = 0; i < n; i++)
		scanf("%d", &x[i]);
	int min = 0, max = 0;
	for (i = 0; i < n; i++) {
		if (x[i] < x[min]) min = i;
		if (x[i] > x[max]) max = i;
	}
	int j, cnt = 0, num, mcnt = 0;

	for (i = x[min]; i <= x[max]; i++) {
		cnt = 0;
		for (j = 0; j < n; j++) {
			if (x[j] == i) {
				cnt++;
			}
			if (cnt > mcnt) {
				mcnt = cnt;
				num = i;
			}
		}
	}
	printf("%d %d", num, mcnt);
	return 0;
}