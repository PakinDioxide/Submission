#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    string s, k;
    cin >> s;
    k = s + s;
    for (int i = 1; i <= n; i++) {
        if (n%i == 0 && s == k.substr(i, n)) {cout << i; return 0;}
    }
}
