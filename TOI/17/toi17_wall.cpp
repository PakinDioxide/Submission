#include <bits/stdc++.h>

using namespace std;

int n, m, ans = 0, kk = 0;
vector <string> a;
vector <vector <bool>> ok, vis;

void flood(int x, int y) {
    if (ok[x][y]) return;
    ok[x][y] = 1;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if ((i == 0 || j == 0) && x+i >= 0 && x+i < n && y+j >= 0 && y+j < m && a[x+i][y+j] == '.' && !ok[x+i][y+j]) {
                flood(x+i, y+j);
            }
        }
    }
}

void ff(int x, int y) {
    if (vis[x][y]) return;
    if (a[x][y] == '.') {
        if (ok[x][y]) kk++;
        return;
    }
    vis[x][y] = 1;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if ((i == 0 || j == 0) && x+i >= 0 && x+i < n && y+j >= 0 && y+j < m && !vis[x+i][y+j]) {
                ff(x+i, y+j);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    a.resize(n);
    ok.resize(n);
    vis.resize(n);
    for (int i = 0; i < n; i++) {ok[i].resize(m); vis[i].resize(m); cin >> a[i];}
    for (int i = 0; i < n; i++) {
        if (!ok[i][0] && a[i][0] == '.') flood(i, 0);
        if (!ok[i][m-1] && a[i][m-1] == '.') flood(i, m-1);
    }
    for (int i = 0; i < m; i++) {
        if (!ok[0][i] && a[0][i] == '.') flood(0, i);
        if (!ok[n-1][i] && a[n-1][i] == '.') flood(n-1, i);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'X' && !vis[i][j]) {
                kk = 0;
                ff(i, j);
                ans = max(kk, ans);
            }
        }
    }
    cout << ans;
}