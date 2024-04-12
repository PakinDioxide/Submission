#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, q;
    cin >> n >> q;
    int a[n], dp1[n], dp2[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    vector <int> d1, d2;
    d1.push_back(a[0]);
    d2.push_back(a[n-1]);
    dp1[0] = dp2[n-1] = 0;
    for (int i = 1; i < n; i++) {
        int idx = lower_bound(d1.begin(), d1.end(), a[i]) - d1.begin();
        if (idx == d1.size()) d1.push_back(a[i]);
        else d1[idx] = a[i];
        dp1[i] = idx;
    }
    for (int i = n-2; i >= 0; i--) {
        int idx = lower_bound(d2.begin(), d2.end(), a[i]) - d2.begin();
        if (idx == d2.size()) d2.push_back(a[i]);
        else d2[idx] = a[i];
        dp2[i] = idx;
    }
    for (int i = 0; i < q; i++) {
        int k;
        cin >> k;
        cout << min(dp1[k], dp2[k]) << '\n';
    }
}