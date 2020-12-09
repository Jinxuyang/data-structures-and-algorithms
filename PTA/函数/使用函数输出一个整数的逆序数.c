#include <stdio.h>

int reverse( int number );

int main()
{
	int n;

	scanf("%d", &n);
	printf("%d\n", reverse(n));

	return 0;
}
int reverse(int number) {
	if (number == 0) return 0;
	if (number < 0) {
		printf("-");
		number = -number;
	}
	while (1) {
		if (number % 10 == 0) number /= 10;
		else break;
	}
	int res = 0;
	while (number) {
		res = number % 10 + res * 10;
		number /= 10;
	}
	return res;

}