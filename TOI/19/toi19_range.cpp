#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <pair <pair <int, int>, int>> a(n);
    for (int i = 0; i < n; i++) {cin >> a[i].first.second >> a[i].first.first; a[i].first.second *= -1; a[i].second = i;}
    sort(a.begin(), a.end());
    int ans[n], ma = 1;
    vector <int> d;
    d.push_back(INT_MIN);
    ans[a[0].second] = 1;
    for (int i = 0; i < n; i++) {
        if (a[i].first == a[i-1].first) {ans[a[i].second] = ans[a[i-1].second]; continue;}
        if (a[i].first.second >= d.back()) {
            d.push_back(a[i].first.second);
            ans[a[i].second] = d.size() - 1;
        } else {
            int idx = upper_bound(d.begin(), d.end(), a[i].first.second) - d.begin();
            if (idx == d.size()) continue;
            else d[idx] = a[i].first.second;
            ans[a[i].second] = idx;
        }
        ma = max(ma, ans[a[i].second]);
    }
    cout << ma << '\n';
    for (int i = 0; i < n; i++) cout << ans[i] << ' ';
}