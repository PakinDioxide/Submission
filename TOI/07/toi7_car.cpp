#include <bits/stdc++.h>

using namespace std;

int m, n, t, ok = 0, a[101][41];
vector <vector <bool>> memo(101, vector<bool>(41));

void solve(int k, int l, string s) {
    if (ok || memo[k][l]) return;
    memo[k][l] = 1;
    if (l == t) {
        for (auto i : s) cout << i << '\n';
        ok = 1;
        return;
    }
    if (k-1 >= 0 && a[l+1][k-1] == 0) solve(k-1, l+1, s+'1');
    if (k+1 < m && a[l+1][k+1] == 0) solve(k+1, l+1, s+'2');
    if (a[l+1][k] == 0) solve(k, l+1, s+'3');
}

int main() {
    cin >> m >> n >> t;
    for (int i = 1; i <= t; i++) {
        for (int j = 0; j < m; j++) cin >> a[i][j];
    }
    solve(n-1, 0, "");
}
