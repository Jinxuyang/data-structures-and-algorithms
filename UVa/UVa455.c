#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
	int T;
	scanf("%d", &T);
	while (T--) {
		char s[100];
		scanf("%s", s);
		int len = strlen(s), count = 1;
		while (count <= len) {
			int ok = 1;
			for (int j = 0; j < len ; j++) {
				if (s[j] != s[j % count] || len % count != 0) {
					ok = 0;
					break;
				}
			}
			if (ok) {
				if (T) {
					printf("%d\n\n", count);
				}
				else printf("%d\n", count);
				break;
			}
			count++;
		}
	}
	return 0;
}