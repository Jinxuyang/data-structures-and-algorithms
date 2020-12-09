#include <iostream>
#include <queue>
#define MAX 10
using namespace std;

int Graph[MAX][MAX], dfsv[MAX] = {0}, bfsv[MAX], N, E;
queue<int> q1;

void DFS(int i) {
	dfsv[i] = 1;
	cout << " " << i;
	for (int j = 0; j < N; j++) {
		if (Graph[i][j] && !dfsv[j]) {
			DFS(j);
		}
	}
}

void BFS(int i) {
	bfsv[i] = 1;
	q1.push(i);
	while (!q1.empty()) {
		int c = q1.front();
		cout << " " << c;
		q1.pop();
		for (int j = 0; j < N; j++) {
			if (Graph[c][j] && !bfsv[j]) {
				q1.push(j);
				bfsv[j] = 1;
			}
		}
	}

}

int main(int argc, char const *argv[])
{
	cin >> N >> E;

	while (E--) {
		int x, y;
		cin >> x >> y;
		Graph[x][y] = 1;
		Graph[y][x] = 1;
	}
	for (int i = 0; i < N; i++) {
		if (!dfsv[i]) {
			cout << "{";
			DFS(i);
			cout << " }" << endl;
		}
	}

	for (int i = 0; i < N; i++) {
		if (!bfsv[i]) {
			cout << "{";
			BFS(i);
			cout << " }" << endl;
		}
	}
	return 0;
}