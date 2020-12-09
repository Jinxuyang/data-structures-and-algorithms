#include <cstdlib>
#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char const *argv[])
{
	int x[3];

	while (cin >> x[0] >> x[1] >> x[2]) {

		if (x[0] == 0 && x[1] == 0 && x[2] == 0) return 0;
		queue<int> u[3];
		string s;

		int cnt = 0;

		while (cin >> s && s != "#") {

			int time = 0, type = 0, i;
			time = ((s[0] - '0') * 10 + (s[1] - '0')) * 60 + ((s[3] - '0') * 10 + (s[4] - '0'));
			cin >> type;
			if (type > 0 && type <= 2) i = 0;
			else if (type > 2 && type <= 4) i = 1;
			else i = 2;

			if (x[i] > 0) {
				x[i]--;
				u[i].push(time + 30);
				cnt += type;
			}
			else {
				if (time + 30 >= u[i].front()) {
//WA的原因是少考虑了一种情况，假设有一桌在35来，而第一桌正在吃的40结束，那么35来的那一桌，需要等到40，才能吃
//一开始不知道怎么回事，只考虑了40以后来的情况
//还是思路不清晰，以后要在本本上好好先模拟一下
					if (time >= u[i].front())
						u[i].push(time + 30);
					else u[i].push(u[i].front() + 30);
					cnt += type;
					u[i].pop();
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}