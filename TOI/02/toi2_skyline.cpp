#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m = 0;
    vector <int> h(255);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        c--;

        m = max(m, c);

        for (int j = a; j < c; j++) if (h[j] < b) h[j] = b;
    }

    int r = 0;

    for (int i = 0; i <= m; i++) {
        if (h[i] != r) {
            cout << i+1 << ' ' << h[i] << ' ';
            r = h[i];
        }
    }
}
