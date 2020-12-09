#include  <stdio.h>
void fun (char  *s, char  *t);
int main()
{	char   s[100], t[100];
	scanf("%s", s);
	fun(s, t);
	printf("The result is: %s\n", t);
	return 0;
}

void fun (char  *s, char  *t) {
	int i, cnt = 0;
	for (i = 0; s[i] != '\0'; i++) {
		cnt++;
		t[i] = s[i];
	}
	int j = cnt;
	for (i = cnt - 1; i >= 0; i--) {
		t[cnt] = s[i];
		cnt++;
	}
}