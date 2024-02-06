#include <bits/stdc++.h>

using namespace std;

int n, k, ma = INT_MIN;
vector <int> m(100001);
vector <vector <int>> par(100001), chi(100001);

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> m[i];
        ma = max(ma, m[i]);
        int o;
        cin >> o;
        for (int j = 0; j < o; j++) {
            int l;
            cin >> l;
            chi[i].push_back(l);
            par[l].push_back(i);
        }
    }
    int l = 0, r = ma + 1, ans = INT_MAX;

    while (l + 1 < r) {
        int i = (l + r) / 2;
        vector <bool> ok(n, true);
        int c = 0;
        for (int j = 0; j < n; j++) {
            if (m[j] > i) {
                ok[j] = false;
                for (auto k : par[j]) ok[k] = false;
                for (auto k : chi[j]) ok[k] = false;
            }
        }
        for (int j = 0; j < n; j++) if (ok[j]) c++;
        if (c >= k) {
            ans = min(i, ans);
            r = i;
        } else l = i;
    }

    cout << ans;
}
