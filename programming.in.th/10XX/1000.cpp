#include <bits/stdc++.h>

using namespace std;

int main() {
    int l, n;
    cin >> l >> n;

    vector <string> t(n);

    for (int i = 0; i < n; i++) cin >> t[i];

    for (int i = 0; i < n-1; i++) {
        int c = 0;
        for (int j = 0; j < l && c <= 2; j++) {
            if (t[i][j] != t[i+1][j]) c++;
        }

        if (c > 2) {
            cout << t[i];
            return 0;
        }
    }

    cout << t[n-1];
}
