#include <bits/stdc++.h>

using namespace std;

int dp[2000][2000];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <char> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int l = 1; l < n; l++) {
        for (int i = 0; i < n-l; i++) {
            int j = i + l;
            for (int k = i; k < j; k++) dp[i][j] = max(dp[i][j], dp[i][k] + dp[k+1][j]);
            if (s[i] == s[j]) dp[i][j] = max(dp[i][j], 1 + dp[i+1][j-1]);
        }
    }
    cout << dp[0][n-1];
}