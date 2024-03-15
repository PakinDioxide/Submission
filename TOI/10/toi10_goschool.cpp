#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int o;
    vector <vector <int>> a(n, vector <int>(m));
    cin >> o;
    for (int i = 0; i < o; i++) {
        int x, y;
        cin >> x >> y;
        a[x-1][y-1] = 1;
    }
    long long dp[n][m];
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0) continue;
            long long k = 0;
            if (i > 0) k += dp[i-1][j];
            if (j > 0) k += dp[i][j-1];
            if (a[i][j]) k = 0;
            dp[i][j] = k;
        }
    }
    cout << dp[n-1][m-1];
}
