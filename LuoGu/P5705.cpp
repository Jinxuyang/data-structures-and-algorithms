#include<bits/stdc++.h>
using namespace std;
string x;
int main(int argc, char const *argv[])
{
    int l;
    cin >> x;
    l = x.size();
    for (int i = l - 1; i >= 0; i--) {
        cout << x[i];
    }
    return 0;
}