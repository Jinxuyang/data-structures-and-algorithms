#include <iostream>
#include <cmath>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	while ((scanf("%d", &n)) != EOF) {
		long long x, temp;
		x = pow(2, n);
		int cnt = 0;
		temp = x;
		while (1) {
			do {
				cnt += temp % 10;
				temp /= 10;
			} while (temp > 0);

			if (cnt >= 10) temp = cnt;
			else break;
		}
		cout << cnt << endl;
	}
	return 0;
}