#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    long long n, m;
    cin >> n >> m;
    long long a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    long long l = 1, r = LLONG_MAX-1;
    while (l < r) {
        long long mid = (l+r)>>1;
        long long c = 0;
        for (int i = 0; i < n && c < m; i++) c += mid/a[i];
        if (c >= m) {
            r = mid;
        } else {
            l = mid+1;
        }
    }
    cout << r;
}
