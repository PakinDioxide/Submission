#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    int a[n], dp[n], eat[n][n];
    for (int i = 0; i < n; i++) {cin >> a[i]; eat[i][i] = a[i];}
    for (int l = 1; l < n; l++) {
        for (int i = 0; i < n-l; i++) {
            int j = i + l;
            eat[i][j] = 0;
            eat[i][j] = max(eat[i+1][j] + a[i], eat[i][j-1] + a[j]) + abs(a[i] - a[j]);
        }
    }
    for (int i = 0; i < n; i++) {
        dp[i] = eat[0][i];
        for (int k = 0; k < i; k++) {
            dp[i] = max(dp[i], dp[k] + eat[k+1][i]);
        }
    }
    cout << dp[n-1];
}