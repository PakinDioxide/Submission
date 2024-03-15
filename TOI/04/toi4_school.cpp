#include <bits/stdc++.h>

using namespace std;

int n, m, p[65][65];
char a[64][64];

void flood(int x, int y, char k) {
    a[x][y] = k;
    for (int i = -1; i <= 1; i++) for (int j = -1; j <= 1; j++) if ((i == 0 || j == 0) && x+i >= 0 && x+i < n && y+j >= 0 && y+j < m && a[x+i][y+j] == 'P') flood(x+i, y+j, k);
}

int main() {
    cin >> m >> n;
    char c = 'a';
    for (int i = 0; i <= n; i++) p[i][0] = 0;
    for (int i = 0; i <= m; i++) p[0][i] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            p[i+1][j+1] = p[i][j+1] + p[i+1][j] - p[i][j];
            if (a[i][j] == 'T') p[i+1][j+1]++;
        }
    }
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        if (a[i][j] == 'P') flood(i, j, c++);
    }
    int ans = 0, pond = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 0; k <= min(n, m); k++) {
                if (k+i <= n && k+j <= m) {
                    if (p[i+k][j+k] - p[i-1][j+k] - p[i+k][j-1] + p[i-1][j-1] == 0) {
                        set <char> s;
                        for (int x = i-1; x < i+k; x++) for (int y = j-1; y < j+k; y++) {
                            if (a[x][y] != 'T' && a[x][y] != 'S') s.insert(a[x][y]);
                        }
                        int pp = s.size();
                        if (ans < (k+1)*(k+1)) {
                            ans = (k+1)*(k+1);
                            pond = pp;
                        } else if (ans == (k+1)*(k+1)) {
                            pond = min(pond, pp);
                        }
                    }
                }
            }
        }
    }
    cout << ans << ' ' << pond;
}
