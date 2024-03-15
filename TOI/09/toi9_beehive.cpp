#include <bits/stdc++.h>

using namespace std;

int n, m, a[1000][1000], ma = 0, cc = 0;
vector <vector <bool>> alr(1000, vector <bool>(1000));
pair <long long, int> dp[1000][1000];

pair <int, int> solve(int r, int c) {
    if (c < 0 || c == m) return {0, 0};
    if (alr[r][c]) return dp[r][c];
    alr[r][c] = true;
    if (r == n-1) return dp[r][c] = {a[r][c], 1};
    pair <int, int> t = solve(r+1, c);
    if (r % 2 == 0) {
        pair <int, int> j = solve(r+1, c-1);
        if (t.first == j.first) dp[r][c] = {t.first+a[r][c], t.second+j.second};
        else {dp[r][c] = max(t, j); dp[r][c].first+=a[r][c];}
    } else {
        pair <int, int> j = solve(r+1, c+1);
        if (t.first == j.first) dp[r][c] = {t.first+a[r][c], t.second+j.second};
        else {dp[r][c] = max(t, j); dp[r][c].first+=a[r][c];}
    }
    return dp[r][c];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
    pair <int, int> t = {0, 0};
    for (int i = 0; i < m; i++) {
        pair <int, int> j = solve(0, i);
        if (t.first == j.first) t.second += j.second;
        if (j.first > t.first) t = j;
    }
    cout << t.first << ' ' << t.second;
}
