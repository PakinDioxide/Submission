#include <bits/stdc++.h>

using namespace std;

int n, m;
double a[3][3], ans = DBL_MAX;

void solve(double mon, int c) {
    if (c == n*m) {
        ans = min(mon, ans);
        return;
    }
    for (int y = 0; y < n; y++) {
        for (int z = 0; z < m; z++) {
            if (a[y][z] != -1) {
                double k = a[y][z];
                a[y][z] = -1;
                for (int i = -1; i <= 1; i++) {
                    for (int j = -1; j <= 1; j++) {
                        if (i+y >= 0 && i+y < n && j+z >= 0 && j+z < m && a[i+y][j+z] != -1) a[i+y][j+z] += 0.1*k;
                    }
                }
                solve(mon+k, c+1);
                for (int i = -1; i <= 1; i++) {
                    for (int j = -1; j <= 1; j++) {
                        if (i+y >= 0 && i+y < n && j+z >= 0 && j+z < m && a[i+y][j+z] != -1) a[i+y][j+z] -= 0.1*k;
                    }
                }
                a[y][z] = k;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
    solve(0, 0);
    printf("%.2lf", ans);
}
