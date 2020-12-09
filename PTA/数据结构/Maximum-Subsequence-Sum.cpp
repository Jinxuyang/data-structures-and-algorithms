#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n, ok = 0;
	int x[100010];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		if (x[i] >= 0) ok = 1;
	}

	if (!ok) {
		printf("0 %d %d", x[0], x[n - 1]);
		return 0;
	}

	int max, sum, first = x[0], last = x[0], temp = x[0];
	max = -1;
	sum = 0;
	for (int i = 0; i < n; i++) {
		sum += x[i];
		if (sum > max) {
			max = sum;
			last = x[i];
			first = temp;
		}

		else if (sum < 0) {
			temp = x[i + 1];
			sum = 0;
		}

	}
	cout << max << " " << first << " " << last;
	return 0;
}