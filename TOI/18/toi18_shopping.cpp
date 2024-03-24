#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    pair <long long, long long> a[n+1];
    a[0] = {0, 0};
    for (int i = 1; i <= n; i++) {
        long long k;
        cin >> k;
        if (k >= 0) {a[i].second = a[i-1].second + k; a[i].first = a[i-1].first;}
        else {a[i].second = a[i-1].second; a[i].first = a[i-1].first - k;}
    }
    for (int i = 0; i < m; i++) {
        long long x, y;
        cin >> x >> y;
        long long l = x+1, r = n, ans = 0;
        while (l <= r) {
            long long mid = (l+r)/2;
            if (a[mid].first - a[x].first < y) {
                ans = max(ans, a[mid].second - a[x].second);
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        cout << ans << '\n';
    }
}