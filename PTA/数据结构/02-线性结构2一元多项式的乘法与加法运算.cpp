#include <iostream>
using namespace std;

struct Node {
	int index;
	int base;
	struct Node *Next;
};
typedef Node *PNode;
typedef PNode List;

List CreatNode() {
	List L = (List)malloc(sizeof(struct Node));
	L->Next = NULL;
	L->index = 0;
	L->base = 0;
	return L;
}

List ReadList(List L) {
	int T;
	cin >> T;
	List temp = L;
	while (T--) {
		temp->Next = CreatNode();
		temp = temp->Next;
		cin >> temp->base;
		cin >> temp->index;
	}
	return L;
}

List AddList(List L1, List L2) {
	List L = CreatNode();
	List temp = L;
	List temp1 = L1->Next, temp2 = L2->Next;
	while (temp1 != NULL && temp2 != NULL) {
		int ok = 1;
		if (temp1 -> index > temp2->index) {
			temp->Next = temp1;
			temp1 = temp1->Next;
		}
		else if (temp1 -> index < temp2->index) {
			temp->Next = temp2;
			temp2 = temp2->Next;
		}
		else {
			ok = 0;
			temp->Next = CreatNode();
			temp = temp->Next;
			temp->base = temp1->base + temp2->base;
			temp->index = temp1->index;
			temp1 = temp1->Next;
			temp2 = temp2->Next;
		}
		if (ok) temp = temp->Next;
	}
	if (temp1 == NULL) temp->Next = temp2;
	if (temp2 == NULL) temp->Next = temp1;
	return L;
}
List MutiList(List L1, List L2) {
	List L = CreatNode(), temp1 = L1->Next, temp2 = L2->Next, temp;
	temp = L;
	int ok = 1;
	while (temp1) {
		if (ok) {
			temp->Next = CreatNode();
			temp = temp->Next;
			ok = 1;
		}

		if (temp1->base + temp2->base != 0) {
			L->index = temp1->index + temp2->index;
			L->base = temp1->base + temp2->base;
		}
		else ok = 0;
		temp1 = temp1->Next;
	}
	temp1 = L1->Next;
	temp2 = temp2 ->Next;
	temp = L;
	while (temp2) {
		while (temp1) {
			int index = temp1->index + temp2->index;
			int base = temp1->base * temp2->base;

			while (temp->Next && temp->Next->index > index) {
				temp = temp->Next;
			}
			if (temp->Next && temp->Next->index == index) {
				if (temp->Next->index + index != 0) {
					temp->Next -> index += index;
				}
				else {
					List T = temp->Next;
					temp->Next = T->Next;
					free(T);
				}
			}
			else {
				List T = CreatNode();
				T->index = index;
				T->base = base;
				List T1 = temp->Next;
				temp -> Next = T;
				T -> Next = T1;
			}
			temp = L;
			temp1 = temp1->Next;
		}
		temp1 = L->Next;
		temp2 = temp2 -> Next;
	}
	return L;
}



void PrintList(List L) {
	List temp = L->Next;
	int ok = 1;
	while (temp != NULL) {
		if (ok) {
			cout << temp->base << " " << temp->index;
			ok = 0;
		}
		else cout << " " << temp->base << " " << temp->index;

		temp = temp->Next;
	}

}
int main(int argc, char const *argv[])
{


	List L1 = CreatNode(), L2 = CreatNode();
	ReadList(L1);
	ReadList(L2);

	List ML = MutiList(L1, L2);
	PrintList(ML);
	cout << endl;
	List AL = AddList(L1, L2);
	PrintList(AL);

	return 0;
}