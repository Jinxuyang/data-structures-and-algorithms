#include <iostream>
using namespace std;

typedef struct
{
	int sta;
	char name[];
} dtoy;
typedef struct $
{
	int sta;
	int step;
} dorder;
dtoy toy[100000];
dorder order[100000];
int main(int argc, char const *argv[])
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> toy[i].sta;
		cin >> toy[i].name;
	}
	for (int i = 0; i < m; i++) {
		cin >> order[i].sta;
		cin >> order[i].step;
	}


	cout << toy[1].name;
	//cout << toy[1].name;
	return 0;
}