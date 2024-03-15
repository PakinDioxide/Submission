#include <bits/stdc++.h>

using namespace std;

vector <vector <int>> adj(26);
vector <char> path;
vector <vector <int>> vis(26, vector <int>(26));
int n, m = 0, c = 0, done = 0;

void dfs(int u) {
    if (done) return;
    if (c == n) {
        path.push_back(u+'A');
        done = 1;
        for (auto i : path) cout << i << ' ';
        return;
    }
    for (auto v : adj[u]) {
        if (!vis[u][v]) {
            vis[u][v] = 1;
            vis[v][u] = 1;
            c++;
            path.push_back(u+'A');
            dfs(v);
            if (done) return;
            c--;
            path.erase(path.end()-1);
            vis[u][v] = 0;
            vis[v][u] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        char s[3];
        cin >> s;
        adj[s[0]-'A'].push_back(s[1]-'A');
        adj[s[1]-'A'].push_back(s[0]-'A');
        m = max({m, s[0]-'A'+1, s[1]-'A'+1});
    }
    int st = 0;
    for (int i = 0; i < m; i++) if (adj[i].size()%2) st = i;
    dfs(st);
}
