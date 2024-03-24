#include <bits/stdc++.h>

using namespace std;

int n;
set <int> adj[500001];
vector <bool> vis(500001);
long long MOD = 1e9+7;

long long fac(int c) {
    long long k = 1;
    while (c > 1) k=(k*c--)%MOD;
    return k;
}

long long dfs(int u) {
    if (vis[u]) return 1;
    vis[u] = 1;
    long long k = 1, c = 0;
    for (auto v : adj[u]) {
        if (!vis[v]) {
            c++;
            k = (k*dfs(v))%MOD;
        }
    }
    if (c == 0) return 1;
    return (fac(c)*k)%MOD;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    int l, r;
    cin >> l;
    l--;
    for (int i = 1; i < 2*n-1; i++) {
        cin >> r;
        r--;
        adj[r].insert(l);
        adj[l].insert(r);
        l = r;
    }
    cout << dfs(r);
}
