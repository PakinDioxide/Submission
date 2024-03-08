#include <bits/stdc++.h>

using namespace std;

int n, c = 0, ans = 0, xx, yy, no = false;
vector <vector <int>> a;

void floodfill(int x, int y) {
    int k = a[x][y];
    a[x][y] = 0;
    if (abs(xx-x) == 2 || abs(yy-y) == 2) no = true;
    c++;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if ((i == 0 || j == 0) && i + x >= 0 && i + x < n && j + y >= 0 && j + y <= n && a[x+i][y+j] == k) {
                floodfill(x+i, y+j);
            }
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        vector <int> temp;
        for (int j = 0; j < n; j++) {
            int t;
            cin >> t;
            temp.push_back(t);
        }
        a.push_back(temp);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] != 0) {
                xx = i;
                yy = j;
                c = 0;
                no = false;
                floodfill(i, j);
                if (c == 3 && !no) ans++;
            }
        }
    }
    cout << ans;
}
