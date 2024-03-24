#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, q;
    cin >> n >> q;
    int p[n+1];
    p[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        p[i] += p[i-1];
    }
    for (int i = n; i > 0; i--) if (p[i-1] > p[i]) p[i-1] = p[i];
    for (int i = 0; i < q; i++) {
        int k, ans;
        cin >> k;
        int l = 0, r = n;
        while (l <= r) {
            int mid = (l+r)/2;
            if (p[mid] <= k) {
                l = mid+1;
                ans = mid;
            } else r = mid-1;
        }
        cout << ans << '\n';
    }
}
