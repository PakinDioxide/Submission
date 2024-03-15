#include <bits/stdc++.h>

using namespace std;

int n, m;
vector <bool> a(9), b(9);

void solve(int k, string s) {
    if (k == n) {cout << s << '\n'; return;}
    if (k == 0) {
        for (int i = 1; i <= n; i++) {
            if (!b[i]) {
                a[i] = 1;
                char l = i + '0';
                solve(k+1, s + l + ' ');
                a[i] = 0;
            }
        }
    } else {
        for (int i = 1; i <= n; i++) {
            if (!a[i]) {
                a[i] = 1;
                char l = i + '0';
                solve(k+1, s + l + ' ');
                a[i] = 0;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        b[k] = true;
    }
    solve(0, "");
}
