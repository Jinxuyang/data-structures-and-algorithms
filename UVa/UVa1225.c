#include <stdio.h>
char x[10010];
int main(int argc, char const *argv[])
{
	int T;
	scanf("%d", &T);
	while (T--) {
		for (int i = 0; i <= 10005; i++) {
			x[i] = i;
		}
		int d;
		scanf("%d", &d);
		int q = 0, w = 0, e = 0, r = 0, t = 0, y = 0, u = 0, j = 0, o = 0, p = 0;
		for (int i = 1; i <= d; i++) {
			int temp = i;
			while (temp) {
				switch (temp % 10) {
				case 0: q++; break;
				case 1: w++; break;
				case 2: e++; break;
				case 3: r++; break;
				case 4: t++; break;
				case 5: y++; break;
				case 6: u++; break;
				case 7: j++; break;
				case 8: o++; break;
				case 9: p++; break;
				}
				temp /= 10;
			}
		}
		printf("%d %d %d %d %d %d %d %d %d %d\n", q, w, e, r, t, y, u, j, o, p);
	}
	return 0;
}