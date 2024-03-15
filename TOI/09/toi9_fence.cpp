#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, k, s;
    cin >> n >> m >> k;
    s = max(n, m);
    vector <vector <int>> p(n+1, vector <int>(m+1));
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        p[x+1][y+1] = 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            p[i+1][j+1] += p[i][j+1] + p[i+1][j] - p[i][j];
        }
    }
    for (int ss = s-1; ss >= 2; ss--) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (ss+i > n || ss+j > m) continue;
                int tr = (p[i+ss][j+ss]-p[i-1][j+ss]-p[i+ss][j-1]+p[i-1][j-1]) - (p[i+ss-1][j+ss-1]-p[i][j+ss-1]-p[i+ss-1][j]+p[i][j]);
                if (tr == 0) {cout << ss+1 << '\n'; return;}
            }
        }
    }
    cout << 0 << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    for (int i = 0; i < 2; i++) solve();
}
