#include <stdio.h>

int fib( int n );
void PrintFN( int m, int n );

int main()
{
	int m, n, t;

	scanf("%d %d %d", &m, &n, &t);
	printf("fib(%d) = %d\n", t, fib(t));
	PrintFN(m, n);

	return 0;
}

int fib(int n) {
	if (n == 0) return 0;
	else if (n == 1) return 1;
	return fib(n - 1) + fib(n - 2);
}

void PrintFN(int m, int n) {
	int i, ok = 1, ojbk = 1;
	for (i = 0; 1; i++) {
		if (fib(i) >= m) {
			if (fib(i) > n) break;
			else {
				ojbk = 0;
				if (ok) {
					printf("%d", fib(i));
					ok = 0;
				}
				else printf(" %d", fib(i));
			}
		}
	}
	if (ojbk) printf("No Fibonacci number");
}