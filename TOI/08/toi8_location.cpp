#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    k--;
    int p[n+1][m+1];
    for (int i = 0; i <= n; i++) p[i][0] = 0;
    for (int i = 0; i <= m; i++) p[0][i] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int t;
            cin >> t;
            p[i][j] = p[i-1][j] + p[i][j-1] - p[i-1][j-1] + t;
        }
    }

    int ans = 0;

    for (int i = 1; i <= n-k; i++) {
        for (int j = 1; j <= m-k; j++) {
            ans = max(ans, p[i+k][j+k] - p[i-1][j+k] - p[i+k][j-1] + p[i-1][j-1]);
        }
    }
    cout << ans;
}
