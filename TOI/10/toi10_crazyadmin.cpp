#include <bits/stdc++.h>

using namespace std;

int n, m, a[100];

pair <int, int> solve(int x) {
    int k = 0, c = 1, p = INT_MIN, q = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (k + a[i] <= x) k += a[i];
        else {q = min(q, k); k = a[i]; c++;}
        p = max(p, k);
    }
    q = min(q, k);
    if (c > m) return {-1, 0};
    if (c < m) q = 0;
    return {p-q, p};
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> m >> n;
    int j = INT_MIN;
    for (int i = 0; i < n; i++) {cin >> a[i]; j = max(j, a[i]);}
    int l = j, r = 150000, ans, mi = INT_MAX;
    while (l < r) {
        int mid = l + (r-l)/2;
        pair <int, int> k = solve(mid);
        if (k.first == -1) l = mid+1;
        else {
            if (mi > k.first) {
                mi = k.first;
                ans = k.second;
            }
            r = mid-1;
        }
    }
    cout << ans;
}
