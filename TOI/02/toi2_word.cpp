#include <bits/stdc++.h>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    string a[m];

    for (int i = 0; i < m; i++) cin >> a[i];
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) if (a[i][j] > 'Z') a[i][j] = a[i][j] - 'a' + 'A';

    int q;
    cin >> q;

    for (int o = 0; o < q; o++) {
        string s;
        bool done = false, can = true;
        cin >> s;

        for (int i = 0; i < s.size(); i++) if (s[i] > 'Z') s[i] = s[i] - 'a' + 'A';

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == s[0]) {
                    for (int x = -1; x <= 1; x++) {
                        for (int y = -1; y <= 1; y++) {
                            if (x != 0 || y != 0) {
                                if (i + (s.size()-1)*x < m && i + (s.size()-1)*x >= 0 && j + (s.size()-1)*y < n && j + (s.size()-1)*y >= 0) {
                                    can = true;
                                    for (int k = 0; k < s.size(); k++) {
                                        if (a[i+k*x][j+k*y] != s[k]) {can = false; break;}
                                    }
                                    if (can) {
                                        cout << i << ' ' << j << '\n';
                                        done = true;
                                        break;
                                    }
                                }
                            }
                        }
                        if (done) break;
                    }
                    if (done) break;
                }
                if (done) break;
            }
            if (done) break;
        }
    }
}
