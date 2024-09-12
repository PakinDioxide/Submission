#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
    int n;
    scanf("%lld", &n);
    pair <int, int> a[n+1];
    for (int i = 1; i <= n; i++) scanf("%lld %lld", &a[i].second, &a[i].first);
    sort(a, a+n);
    pair <int, int> dp[n+1][2];
    float c[n+1][2];
    dp[0][0] = dp[0][1] = {0, 0};
    c[0][0] = c[0][1] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = c[i-1][0] >= c[i-1][1] ? dp[i-1][0] : dp[i-1][1];
        dp[i][1] = make_pair(dp[i][0].first + a[i].second, max(dp[i][0].second, a[i].first));
        c[i][0] = (float) dp[i][0].first / dp[i][0].second;
        c[i][1] = (float) dp[i][1].first / dp[i][1].second;
    }
    printf("%lld %lld", c[n][0] >= c[n][1] ? dp[n][0].first : dp[n][1].first, c[n][0] > c[n][1] ? dp[n][0].second : dp[n][1].second);
}
