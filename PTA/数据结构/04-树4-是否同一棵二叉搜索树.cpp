#include<iostream>
#include<cstdlib>
using namespace std;

struct TreeNode
{
	int name, flag;
	struct TreeNode *L;
	struct TreeNode *R;
};
typedef struct TreeNode *Tree;

Tree BuildNode() {
	Tree Node;
	Node = (Tree)malloc(sizeof(struct TreeNode));
	Node->L = Node->R = NULL;
	Node->flag = 1;
	return Node;
}

void Insert(Tree T, int temp) {
	if (T->name > temp) {
		if (T->L == NULL) {
			T->L = BuildNode();
			T->L->name = temp;
		}
		else Insert(T->L, temp);
	}
	else {
		if (T->R == NULL) {
			T->R = BuildNode();
			T->R->name = temp;
		}
		else Insert(T->R, temp);
	}
}

Tree BulidTree(Tree T, int N) {
	int temp;
	Tree TempTree = T;
	cin >> temp;
	TempTree->name = temp;
	for (int i = 0; i < N - 1; i++) {
		cin >> temp;
		Insert(TempTree, temp);
	}
	return T;
}
bool Judge(Tree T, int temp) {

	if (T->name == temp) {
		T->flag = 0;
		return true;
	}

	else if (T->name > temp) {
		if (T->L != NULL && T->flag == 0) {
			return Judge(T->L, temp);
		}
		else return false;
	}
	else {
		if (T->R != NULL && T->flag == 0) {
			return Judge(T->R, temp);
		}
		else return false;
	}

}
void ResetTree(Tree T) {
	T->flag =  1;
	if (T->L != NULL && T->R != NULL) {
		ResetTree(T->L);
		ResetTree(T->R);
	}
	else if (T->L != NULL && T->R == NULL) ResetTree(T->L);
	else if (T->L == NULL && T->R != NULL) ResetTree(T->R);
}
int main(int argc, char const *argv[])
{
	while (1) {
		int N, L;
		cin >> N;
		if (N == 0) return 0;
		cin >> L;
		Tree T = BuildNode();
		T = BulidTree(T, N);
		while (L--) {
			int temp, ok = 1;
			for (int i = 0; i < N; i++) {
				cin >> temp;
				if (!Judge(T, temp)) {
					ok = 0;
				}
			}
			if (ok)
				cout << "Yes\n";
			else cout << "No\n";
			ResetTree(T);
		}

	}
	return 0;
}