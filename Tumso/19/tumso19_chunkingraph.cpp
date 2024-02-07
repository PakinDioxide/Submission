#include <bits/stdc++.h>

using namespace std;

long long m, n, ans = 0, id = 0, N = 5e5+1;

vector <bool> vis(N);
vector <long long> ids(N), low(N);
vector <vector <long long>> adj(N);

void dfs(int u, int p) {
    vis[u] = true;
    ids[u] = low[u] = ++id;
    for (auto v : adj[u]) {
        if (p == v) continue;
        if (!vis[v]) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
        } else {
            low[u] = min(low[u], ids[v]);
        }
    }

    if (ids[u] == low[u]) ans++;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0; i < n; i++) if (!vis[i]) dfs(i, -1);

    cout << ans;
}
