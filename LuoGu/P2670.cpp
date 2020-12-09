#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, m, mp[110][110];
    char temp;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> temp;
            if (temp == '*') mp[i][j] = -1;
            else mp[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mp[i][j] == -1) {
                for (int y = -1; y <= 1; y++) {
                    for (int x = -1; x <= 1; x++) {
                        if (mp[i + y][j + x] >= 0) {
                            mp[i + y][j + x]++;
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mp[i][j] == -1) cout << "*";
            else cout << mp[i][j];
        }
        cout << "\n";
    }
    return 0;
}