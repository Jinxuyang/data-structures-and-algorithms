#include <iostream>
#include <cstring>
using namespace std;
int main(int argc, char const *argv[])
{
	char s[100];
	int cnt = 0;
	while (cin >> s) {
		if (strcmp(s, "<br>") == 0) {
			cout << "\n";
			cnt = 0;
			continue;
		}
		else if (strcmp(s, "<hr>") == 0) {
			if (cnt > 0)
				cout << "\n";
			for (int i = 0; i < 80; i++)
				cout << "-";
			cout << "\n";
			cnt = 0;
			continue;
		}

		cnt += strlen(s);
		if (cnt != 0) {
			cout << " ";
			cnt++;
		}
		if (cnt  >= 80) {
			cout << "\n";
			cnt = 0;
		}


		cout << s;
		cnt += strlen(s);
	}
	cout << endl;
	return 0;
}