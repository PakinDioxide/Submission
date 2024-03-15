#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    char a[3][3][4] = {{{'0'}, {'A', 'B', 'C'}, {'D', 'E', 'F'}}, {{'G', 'H', 'I'}, {'J', 'K', 'L'}, {'M', 'N', 'O'}}, {{'P', 'Q', 'R', 'S'}, {'T', 'U', 'V'}, {'W', 'X', 'Y', 'Z'}}};
    pair <int, int> b[9] = {{0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2}};
    string s;
    cin >> n;
    int x, y, j, k;
    for (int o = 0; o < n; o++) {
        if (o == 0) {
            cin >> j >> k;
            x = b[--j].first;
            y = b[j].second;
        } else {
            int p, q;
            cin >> q >> p >> k;
            x += p;
            y += q;
        }

        if (x == 0 && y == 0) {
            for (int i = 0; i < k && !s.empty(); i++) s.erase(s.end()-1);
        } else if (x == 2 && (y == 0 || y == 2)) {
            k = (k+3) % 4;
            s.push_back(a[x][y][k]);
        } else {
            k = (k+2) % 3;
            s.push_back(a[x][y][k]);
        }
    }
    if (s.empty()) cout << "null";
    else cout << s;
}
