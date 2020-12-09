#include <iostream>
#define MaxTree 10
using namespace std;
struct TreeNode {
	char name;
	int L, R;
} T1[MaxTree], T2[MaxTree];
typedef struct TreeNode Tree;

int BulidTree(struct TreeNode T[]) {
	int c, check[MaxTree], root;
	cin >> c;
	if (c) {
		for (int i = 0; i < MaxTree; i++) check[i] = -1;
		for (int i = 0; i < c; i++) {
			cin >> T[i].name;
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
		for (int i = 0; i < c; i++) {
			if (check[i] == -1) {
				root = i;
				break;
			}
		}
	}
	else root = -1;
	return root;
}
bool isomorphic(int R1, int R2) {
	if (R1 == -1 && R2 == -1) return true;
	if ((R1 == -1 && R2 != -1) || (R1 != -1 && R2 == -1)) return false;
	if (T1[R1].name != T2[R2].name) return false;
	if (T1[R1].L == -1 && T2[R2].L == -1) return isomorphic(T1[R1].R, T2[R2].R);
	if ( ( (T1[R1].L != -1) && (T2[R2].L != -1) ) && ( (T1[T1[R1].L].name) == (T2[T2[R2].L].name) ) )
		return ( isomorphic( T1[R1].L, T2[R2].L ) && isomorphic( T1[R1].R, T2[R2].R ) );
	else
		return ( isomorphic( T1[R1].L, T2[R2].R) && isomorphic( T1[R1].R, T2[R2].L ) );

}
int main(int argc, char const *argv[])
{
	int R1, R2;
	R1 = BulidTree(T1);
	R2 = BulidTree(T2);
	if (isomorphic(R1, R2)) cout << "Yes";
	else cout << "No";

	return 0;
}