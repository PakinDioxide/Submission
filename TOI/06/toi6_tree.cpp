#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    for (int i = 0; i < 5; i++) {
        int n;
        cin >> n;
        vector <set <int>> a(n+1), b(n+1);
        for (int j = 0; j < n-1; j++) {
            int x, y;
            cin >> x >> y;
            a[x].insert(y);
            a[y].insert(x);
        }
        for (int j = 0; j < n-1; j++) {
            int x, y;
            cin >> x >> y;
            b[x].insert(y);
            b[y].insert(x);
        }
        if (a == b) cout << 'Y';
        else cout << 'N';
    }
}
