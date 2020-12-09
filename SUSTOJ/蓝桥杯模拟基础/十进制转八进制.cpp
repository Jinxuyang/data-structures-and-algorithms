#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int x, cnt = 0, s[100000];
	cin >> x;
	for (int i = 0; x; i++) {
		s[i] = x % 8;
		cnt++;
		x /= 8;
	}
	for (int i = cnt - 1; i >= 0; i--) {
		cout << s[i];
	}
	return 0;
}