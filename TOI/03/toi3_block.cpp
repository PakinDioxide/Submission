#include <bits/stdc++.h>

using namespace std;

long long m, n, score = 0;
vector <vector <char>> a;

void merg(int x, int y, char prv) {
    if (a[x][y] == '-' || a[x][y] == '#') return;
    a[x][y] = '-';
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if ((i == 0 || j == 0) && x+i >= 0 && x+i < m && y+j >= 0 && y+j < n && a[x+i][y+j] == prv) {
                score += 5;
                merg(x+i, y+j, prv);
            }

        }
    }
}

void mergall() {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int o = score;
            char oo = a[i][j];
            merg(i, j, a[i][j]);
            if (score == o) a[i][j] = oo;
            else score += 5;
        }
    }
}
void fall() {
    for (int i = 0; i < n; i++) {
        for (int j = m-2; j >= 0; j--) {
            if (a[j][i] == '-' || a[j][i] == '#') continue;
            int k = j;
            while (k < m-1 && a[k+1][i] == '-') {
                a[k+1][i] = a[k][i];
                a[k++][i] = '-';
            }
        }
    }
}

void mov() {
    int x, y;
    char c;
    cin >> x >> y >> c;
    if (a[x][y] == '-' || a[x][y] == '#') {score -= 5; return;}
    if (c == 'L') {
        if (y == 0 || a[x][y-1] != '-') {score -= 5; return;}
        a[x][y-1] = a[x][y];
        a[x][y] = '-';
        fall();
    } else {
        if (y == m-1 || a[x][y+1] != '-') {score -= 5; return;}
        a[x][y+1] = a[x][y];
        a[x][y] = '-';
        fall();
    }
}

int main() {
    cin >> m >> n;

    a.resize(m);
    for (int i = 0; i < m; i++) {
        a[i].resize(n);
        for (int j = 0; j < n; j++) cin >> a[i][j];
    }

    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int bef = score;
        mov();
        if (score < bef) continue;
        vector <vector <char>> temp;
        do {
            temp = a;
            mergall();
            fall();
        } while (temp != a);
    }

    cout << score << '\n';
    for (int x = 0; x < m; x++) {
        for (int y = 0; y < n; y++) {
            cout << a[x][y] << ' ';
        }
        cout << '\n';
    }
}
