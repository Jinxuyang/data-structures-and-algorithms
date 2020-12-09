//不会写
#include <iostream>
#include <cstdlib>
using namespace std;
struct TreeNode
{
	int LH, RH;
	int value, BF = LH - RH;
	struct TreeNode *L;
	struct TreeNode *R;
};
typedef struct TreeNode *Tree;

Tree BuildNode() {
	Tree T = (Tree)malloc(sizeof(struct TreeNode));
	T->value = T->LH = T -> RH = T->BF = 0;
	T->L = T->R = NULL;
	return T;
}

void InsertNode(Tree T, int value) {
	if (T->value > value) {
		if (T->L == NULL) {
			T->L = BuildNode();
			T->L->value = value;
			T->LH++;
		}
		else Insert(T->L, value);
	}
	else {
		if (T->R == NULL) {
			T->R = BuildNode();
			T->R->name = value;
			T->RH++;
		}
		else Insert(T->R, value);
	}


}

Tree BuildTree(Tree T, int N) {
	Tree TempTree = T;
	int temp;
	cin >> temp;
	TempTree->value = temp;
	for (int i = 0; i < N - 1; i++) {
		cin >> temp;
		InsertNode(TempTree, temp);
	}
	return T;
}
Tree AdjustTree(Tree T) {

}
int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	Tree T = ;
	BuildTree()
	return 0;
}