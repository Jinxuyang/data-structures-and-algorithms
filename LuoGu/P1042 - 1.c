#include<stdio.h>
int main(int argc, char const *argv[])
{
	char ch[62510], x;
	int w = 0, l = 0, count = 0, z = 1;

	while ((x = getchar()))
	{
		ch[count] = x;
		count++;
		if (x == 'E') break;
	}


	for (int i = 0; i < count; ++i)
	{
		if (ch[i] == 'W') w++;
		else if (ch[i] == 'L') l++;


		if (ch[i] == 'E') {
			printf("%d:%d\n\n", w, l);
		}
		if (w - l >= 2 || l - w >= 2) {
			if (w >= 11 || l >= 11) {
				printf("%d:%d\n", w, l);
				w = 0;
				l = 0;
			}
		}

	}
	w = 0;
	l = 0;

	for (int i = 0; i < count; ++i)
	{
		if (ch[i] == 'W') w++;
		else if (ch[i] == 'L') l++;


		if (ch[i] == 'E') {
			printf("%d:%d", w, l);
		}
		if (w - l >= 2 || l - w >= 2) {
			if (w >= 21 || l >= 21) {
				printf("%d:%d\n", w, l);
				w = 0;
				l = 0;
			}
		}

	}

	return 0;
}