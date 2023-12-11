#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;

    cin >> n;

    vector <vector <int>> pattern(n);

    for (int i = 0; i < n; i++) pattern[i].resize(70);

    for (int i = 0; i < n; i++) {
        int a, b, c;

        cin >> a >> b >> c;
        b--;
        a--;

        for (int j = b; j < b+c && j < 70; j++) pattern[a][j] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 70; j++) {
            if (pattern[i][j]) cout << 'x';
            else cout << 'o';
        }
        cout << '\n';
    }
}
