#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, k, l, jj;
    cin >> n >> m >> k >> l;
    int a[n], v = 0;
    vector <int> p(10000001);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = v; j <= a[i]; j++) p[j] = i;
        p[a[i]+1] = i+1;
        v = a[i]+1;
    }
    jj = a[n-1]+1;
    for (int i = 0; i < k; i++) {
        int b[m], ma = -1, ans = 0;
        for (int i = 0; i < m; i++) {
            cin >> b[m];
            int le = b[m]-l+1, ri = b[m]+l+1;
            if (le <= jj && ri > jj) ri = jj;
            else if (le > jj) continue;
            if (le <= 0) le = 1;
            if (ma < le) ans += p[ri] - p[le-1];
            else if (ma < ri) ans += p[ri] - p[ma];
            ma = ri;
        }
        cout << ans << '\n';
    }
}
