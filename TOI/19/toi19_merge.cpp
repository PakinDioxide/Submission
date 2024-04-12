#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    int a[n+2], b[m+2], pa[n+1], pb[m+1];
    a[0] = b[0] = INT_MIN;
    pa[0] = pb[0] = 0;
    a[n+1] = b[m+1] = INT_MAX;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {cin >> pa[i]; pa[i] += pa[i-1];}
    for (int i = 1; i <= m; i++) cin >> b[i];
    for (int i = 1; i <= m; i++) {cin >> pb[i]; pb[i] += pb[i-1];}
    for (int i = 0; i < q; i++) {
        int al, be, k;
        cin >> al >> be >> k;
        long long l = -1e9, r = 1e9, ans = 0;
        while (l <= r) {
            long long mid = (l+r)/2;
            int idxa = upper_bound(a, a+n+1, mid) - a - 1;
            int idxb = upper_bound(b, b+m+1, (mid-be)/al) - b - 1;
            if (pa[idxa] + pb[idxb] >= k) {ans = mid; r = mid-1;}
            else l = mid+1;
        }
        cout << ans << '\n';
    }
}