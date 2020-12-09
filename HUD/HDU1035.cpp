#include <iostream>
#include <cstring>
using namespace std;
int main(int argc, char const *argv[])
{
	while (1) {
		int n, m, ent;
		cin >> n >> m >> ent;
		if (n == 0 && m == 0 && ent == 0) return 0;
		char mp[10][10];
		int sta[10][10];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> mp[i][j];
				sta[i][j] = 0;
			}
		}
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				sta[i][j] = 0;
			}
		}

		int step = 0, tag = 0, i = 0, j = ent - 1;
		while (1) {
			step++;
			if (mp[i][j] == 'N') {
				if (i - 1 >= 0) {
					i--;
					if (sta[i][j]) {
						tag = 1;
						break;
					}
					else {
						sta[i + 1][j] = step;
					}
				}
				else break;
			}

			else if (mp[i][j] == 'S') {
				if (i + 1 < n ) {
					i++;
					if (sta[i][j]) {

						tag = 1;
						break;
					}
					else {
						sta[i - 1][j] = step;
					}
				}
				else break;
			}

			else if (mp[i][j] == 'E') {
				if (j + 1 < m) {
					j++;
					if (sta[i][j]) {
						tag = 1;
						break;
					}
					else {
						sta[i][j - 1] = step;
					}
				}
				else break;
			}

			else if (mp[i][j] == 'W') {
				if (j - 1 >= 0) {
					j--;
					if (sta[i][j]) {
						tag = 1;
						break;
					}
					else {
						sta[i][j + 1] = step;
					}
				}
				else break;
			}

		}
		if (tag) cout << sta[i][j] - 1 << " step(s) before a loop of " << step - sta[i][j] + 1 << " step(s)" << endl;
		else cout << step << " step(s) to exit" << endl;
	}
}