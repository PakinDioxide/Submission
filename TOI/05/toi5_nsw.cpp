#include <bits/stdc++.h>

using namespace std;

int main() {
    char key[4], a[3][9];
    string o, ans;
    cin >> key >> o;
    for (int i = 0; i < 3; i++) {
        int k = key[i];
        for (int j = 0; j < 9; j++) {
            a[i][j] = k;
            k++;
            if (k > '9') k = '1';
        }
    }
    for (auto p : o) {
        ans += a[2][a[1][a[0][p-'1']-'1']-'1'];
        for (int j = 0; j < 9; j++) {
            a[0][j] += key[0]-'0';
            if (a[0][j] > '9') a[0][j] -= 9;
            a[1][j]--;
            if (a[1][j] <= '0') a[1][j] += 9;
            a[2][j] += key[2]-'0';
            if (a[2][j] > '9') a[2][j] -= 9;
        }
    }
    cout << ans;
}
