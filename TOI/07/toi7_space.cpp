#include <bits/stdc++.h>

using namespace std;

int n;

void solve(string s) {
    if (s.size() == n) {
        for (int i = n-1; i >= 0; i--) {
            if (s[i] == '0') {
                cout << s << ' ';
                s[i] = '1';
                cout << s << '\n';
                s[i] = '0';
            }
        }
        return;
    }
    solve(s+'0');
    solve(s+'1');
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    solve("");
}
