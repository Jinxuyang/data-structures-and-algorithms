#include <stdio.h>
#include <string.h>

#define MAXN 20

//typedef enum {false, true} bool;

bool palindrome( char *s );

int main()
{
	char s[MAXN];

	scanf("%s", s);
	if ( palindrome(s) == true )
		printf("Yes\n");
	else
		printf("No\n");
	printf("%s\n", s);

	return 0;
}

bool palindrome(char *s) {
	int len = strlen(s), i, IsTure = 1, cnt = 0;
	for (i = 0; i < len / 2; i++) {
		if (s[i] != s[len - i - 1]) {
			IsTure = 0;
			break;
		}
	}
	if (IsTure) return true;
	else return false;

}