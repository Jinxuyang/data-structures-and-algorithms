#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n, ok = 0;
	int x[100010];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		if (x[i] > 0) ok = 1;
	}

	if (!ok) return 0;

	int max, sum;
	max = sum = 0;
	for (int i = 0; i < n; i++) {
		sum += x[i];
		if (sum > max)
			max = sum;
		else if (sum < 0)
			sum = 0;
	}
	cout << max;
	return 0;
}