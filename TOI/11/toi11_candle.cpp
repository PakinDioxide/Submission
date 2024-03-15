#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    char a[n][m];
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        if (a[i][j] == '1') {
            ans++;
            queue <pair <int, int>> q;
            q.push({i, j});
            a[i][j] = 0;
            while (!q.empty()) {
                int x = q.front().first, y = q.front().second;
                q.pop();
                for (int i = -1; i <= 1; i++) {
                    for (int j = -1; j <= 1; j++) {
                        if (i == 0 && j == 0) continue;
                        if (x+i >= 0 && x+i < n && y+j >= 0 && y+j < m && a[x+i][y+j] == '1' && !(i == 0 && j == 0)) {a[x+i][y+j] = '0'; q.push({x+i, y+j});}
                    }
                }
            }
        }
    }
    cout << ans;
}
