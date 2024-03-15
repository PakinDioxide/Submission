#include <bits/stdc++.h>

using namespace std;

int main() {
    vector <vector <char>> a(100, vector <char> (1000, '.'));
    int n, hh = 0, w = 0;
    cin >> n;
    for (int o = 0; o < n; o++) {
        int p, q;
        cin >> p >> q;
        w = max(w, p+2*q-1);
        hh = max(hh, q-1);
        int x = p-1, y = 0;
        while (y < q) {
            if (a[y][x] == '.') a[y][x] = '/';
            else if (a[y][x] == '\\') a[y][x] = 'v';
            for (int i = 0; i < y; i++) a[i][x] = 'X';
            y++;
            x++;
        }
        y--;
        while (y >= 0) {
            if (a[y][x] == '.') a[y][x] = '\\';
            else if (a[y][x] == '/') a[y][x] = 'v';
            for (int i = 0; i < y; i++) a[i][x] = 'X';
            y--;
            x++;
        }
    }

    for (int i = hh; i >= 0; i--) {
        for (int j = 0; j < w; j++) {
            cout << a[i][j];
        }
        cout << '\n';
    }
}
