#include<stdio.h>
#include<ctype.h>
#include<string.h>
const float ex[] = {67, 12.01, 72, 1.008, 79, 16.00, 78, 14.01} ;
int main(int argc, char const *argv[])
{
	int T;
	scanf("%d", &T);
	while (T--) {
		char s[100];
		scanf("%s", s);
		int len = strlen(s);
		double res = 0.0;
		for (int i = 0; i < len; i++) {

			if (isalpha(s[i])) {
				if (!isalpha(s[i + 1]) && i + 1 < len) {
					int n = 1;
					while (!isalpha(s[i + n]) && i + n < len) {
						n++;
					}
					int temp1 = 1, temp2 = 0;
					for (int j = i + n - 1; j > i; j--) {
						temp2 += (s[j] - 48) * temp1;
						temp1 *= 10;
					}

					for (int j = 0; j < 8; j++) {
						if (s[i] == ex[j]) {
							res += ex[j + 1] * temp2;
							break;
						}
					}
				}
				else {
					for (int j = 0; j < 8; j++) {
						if (s[i] == ex[j]) {
							res += ex[j + 1];
							break;
						}
					}

				}
			}

		}
		printf("%.3lf\n", res);
	}
	return 0;
}