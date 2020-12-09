#include <iostream>
#include <queue>
using namespace std;
struct TreeNode {
	int L, R;
} T[10];
int ok = 1;
queue<int> q;
void Search(int root) {
	if (root == -1) return;
	q.push(root);

	while (!q.empty()) {
		int Temp = q.front();
		if (T[Temp].L == -1 && T[Temp].R == -1) {
			if (ok) {
				cout << Temp ;
				ok = 0;
			}
			else cout << " " << Temp;
		}
		else {
			if (T[Temp].L != -1 && T[Temp].R == -1 ) {
				q.push(T[Temp].L);
			}
			else if (T[Temp].L == -1 && T[Temp].R != -1) {
				q.push(T[Temp].R);
			}
			else {
				q.push(T[Temp].L);
				q.push(T[Temp].R);
			}
		}
		q.pop();
	}
}
int main(int argc, char const *argv[])
{
	int t, check[10], root = -1;
	cin >> t;
	if (t) {
		for (int i = 0; i < t; i++) check[i] = 1;
		for (int i = 0; i < t; i++) {
			char TempL, TempR;
			cin >> TempL >> TempR;
			if (TempL == '-') T[i].L = -1;
			else {
				T[i].L = TempL - '0';
				check[T[i].L] = 0;
			}

			if (TempR == '-') T[i].R = -1;
			else {
				T[i].R = TempR - '0';
				check[T[i].R] = 0;
			}
		}
		for (int i = 0; i < t; i++) {
			if (check[i] == 1) {
				root = i;
				break;
			}
		}
	}
	else root = -1;
	Search(root);

	return 0;
}