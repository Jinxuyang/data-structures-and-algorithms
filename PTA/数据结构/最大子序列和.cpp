#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n, x[100010], ok = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		if (x[i] >= 0) ok = 1;
	}

	if (!ok) return 0;

	int cnt, maxsum = 0;
	for (int i = 0; i < n; i++) {
		cnt = x[i];
		for (int j = i + 1; j < n; j++) {
			cnt += x[j];
			if (cnt > maxsum)
				maxsum = cnt;
		}

	}
	if (ok) cout << maxsum;

	return 0;
}
