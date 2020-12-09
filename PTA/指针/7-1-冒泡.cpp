#include <iostream>
#include <algorithm>
using namespace std;
void bubbleSort(int *p, int c) {
	sort(p, p + c);
}
int main(int argc, char const *argv[])
{
	int T;
	cin >> T;
	int x[100000], cnt = 0;
	for (int i = 0; i < T; i++) {
		cin >> x[i];
		cnt ++;
	}
	bubbleSort(x, cnt);
	for (int i = 0; i < T; i++) {
		cout << x[i] << " ";
	}
	return 0;
}