#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    long long n, l = 0, r = 0;
    cin >> n;
    long long a[n];
    for (int i = 0; i < n; i++) {cin >> a[i]; r = max(r, a[i]);}
    long long ans = INT_MAX;
    while (l <= r) {
        long long mid = (l+r)/2, k = -1;
        bool ok = 1;
        for (int i = 0; i < n; i++) {
            if (a[i] > mid && k == -1) k = a[i];
            else if (a[i] > mid && k == a[i]) k = -1;
            else if (a[i] > mid) {ok = 0; break;}
        }
        if (ok) {
            r = mid-1;
            ans = min(mid, ans);
        } else {
            l = mid+1;
        }
    }
    cout << ans;
}
