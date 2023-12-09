#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    string s[n];

    for (int i = 0; i < n; i++) cin >> s[i];

    sort(s, s+n);

    cout << s[0] << '\n';

    for (int i = 1; i < n; i++) if (s[i] != s[i-1]) cout << s[i] << '\n';
}
