#include <bits/stdc++.h>

using namespace std;

int par[3000], ans = 0, n, m, s, d, p, c = 0;
vector <vector <pair <int, int>>> adj;
vector <bool> vis;

int fi(int x) {
    if (par[x] != x) x = fi(par[x]);
    return par[x];
}

void dfs(int u, int w) {
    if (u == d) ans = max(ans, w);
    if (vis[u]) return;
    vis[u] = 1;
    for (auto [v, ww] : adj[u]) {
        dfs(v, min(ww, w));
    }
    vis[u] = 0;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) par[i] = i;
    priority_queue <pair <int, pair <int, int>>> edge;
    adj.resize(n);
    vis.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge.push({w-1, {u-1, v-1}});
    }
    cin >> s >> d >> p;
    s--;
    d--;
    while (!edge.empty()) {
        int w = edge.top().first, u = edge.top().second.first, v = edge.top().second.second;
        edge.pop();
        if (fi(par[u]) != fi(par[v])) {
            par[fi(u)] = par[fi(v)];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
            c++;
            if (par[fi(s)] == par[fi(d)]) {
                cout << ceil((float)p/w);
                return 0;
            }
        }
    }
    dfs(s, INT_MAX);
    cout << ceil((float)p/ans);
}