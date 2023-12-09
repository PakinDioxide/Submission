#include <bits/stdc++.h>

using namespace std;

int main() {
    int m, n, l, k, c, total = 0;

    cin >> m >> n >> l >> k >> c;

    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) {
        int k;
        cin >> k;
        total += k;
    }

    total += l*k*c;

    cout << total/c + (total % c == 0 ? 0 : 1);
}
