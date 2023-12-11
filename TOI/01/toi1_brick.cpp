#include <bits/stdc++.h>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector <string> brick(m);

    for (int i = 0; i < m; i++) cin >> brick[i];

    for (int i = 0; i < n; i++) {
        int fall;
        cin >> fall;

        int last = m-1;

        for (int j = 0; j < m; j++) {
            if (brick[j][i] == 'O') {
                last = j-1;
                break;
            }
        }

        for (int j = last; j >= 0 && fall > 0; j--) {
            brick[j][i] = '#';
            fall--;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << brick[i][j];
        }
        cout << "\n";
    }
}
