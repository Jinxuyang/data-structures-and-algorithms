#include <iostream>
using namespace std;

struct Node
{
	int address, data, next;
	struct Node *link;
};
typedef struct Node *node;
node CreateNode() {
	node N = (node)malloc(sizeof(struct Node));
	return N;
}
node Read() {
	node N = CreateNode();
	node temp  = N;
	cin >> N->address >> N->data >> N->next;
	int T = N->data;
	while (T--) {
		temp->link = CreateNode();
		temp = temp->link;
		cin >> temp->address >> temp->data >> temp->next;
	}
	return N;
}
node SortList(node N) {
	int x = N->data;
	node sortedN, temp = N->link;
	while (sortedN) {
		if (temp->data == N->data) {
			sortedN = temp;
			sortedN = sortedN->link;
		}
		temp = temp->link;
	}
	while ()


	}
int main(int argc, char const *argv[])
{

	return 0;
}