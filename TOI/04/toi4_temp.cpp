#include <bits/stdc++.h>

using namespace std;

int n, x, y, m = INT_MIN, a[21][21];

void mov(int p, int q) {
    m = max(a[p][q], m);
    int o = a[p][q];
    a[p][q] = 100;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if ((i == 0 || j == 0) && p+i >= 0 && p+i < n && q+j >= 0 && q+j < n && a[p+i][q+j] != 100 && a[p+i][q+j] > o) mov(p+i, q+j);
        }
    }
}

int main() {
    cin >> n >> x >> y;
    x--;
    y--;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j];
    mov(y, x);
    cout << m;
}
