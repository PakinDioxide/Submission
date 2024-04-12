#include <bits/stdc++.h>

using namespace std;

int n, k, d, a[350];
long long MOD = 1e9+7;

long long memo[350][350][15], vis[350][350][15];

long long solve(int l, int r, int c) {
    if (memo[l][r][c] >= 0) return memo[l][r][c];
    if (c == 0) return memo[l][r][c] = 1;
    if (l == r-1 || c == k) return memo[l][r][c] = 0;
    int fin = (a[r]+a[l])/2, i1 = lower_bound(a+l, a+r, fin-d) - a, i2 = upper_bound(a+l, a+r, fin+d) - a;
    long long ans = 0;
    for (int i = i1; i <= i2; i++) {
        if (a[r] - a[i] == 0 || a[i] - a[l] == 0) continue;
        if (abs((a[r] - a[i]) - (a[i] - a[l])) <= d) {
            long long x = solve(l, i, c-1), y = solve(i, r, c-1);
            ans += x*y;
            ans %= MOD;
        }
    }
    return memo[l][r][c] = ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k >> d;
    a[0] = 0;
    for (int i = 1; i <= n; i++) {cin >> a[i]; a[i] += a[i-1];}
    for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) for (int l = 0; l <= k; l++) memo[i][j][l] = -1;
    cout << solve(0, n, k-1)%MOD;
}