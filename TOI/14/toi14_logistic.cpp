#include <bits/stdc++.h>

using namespace std;

int dp[101][101][2], vis[101];
vector <pair <int, int>> adj[101];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    int price[n+1], s, d, cap, m;
    for (int i = 1; i <= n; i++) cin >> price[i];
    cin >> s >> d >> cap >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            dp[i][j][0] = dp[i][j][1] = INT_MAX;
        }
    }
    priority_queue <pair <int, int>> q;
    q.emplace(0, s);
    dp[s][0][0] = dp[s][0][1] = 0;
    while (!q.empty()) {
        int u = q.top().second;
        q.pop();
        for (int i = 1; i <= cap; i++) {
            dp[u][i][0] = min(dp[u][i-1][0] + price[u], dp[u][i][0]);
            dp[u][i][1] = min({dp[u][0][0], dp[u][i-1][1] + price[u], dp[u][i][1]});
        }
        for (auto [v, w] : adj[u]) {
            int d1 = 0, d2 = 0;
            for (int i = w; i <= cap; i++) {
                if (dp[v][i-w][0] > dp[u][i][0]) {
                    dp[v][i-w][0] = dp[u][i][0];
                    if (!d1) q.emplace(-dp[v][i-w][0], v);
                    d1 = 1;
                }
                if (dp[v][i-w][1] > dp[u][i][1]) {
                    dp[v][i-w][1] = dp[u][i][1];
                    if (!d2) q.emplace(-dp[v][i-w][1], v);
                    d2 = 1;
                }
            }
        }
    }
    cout << dp[d][cap][1];
}