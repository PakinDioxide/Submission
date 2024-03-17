#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, x, y, z;
    cin >> n >> m >> x >> y >> z;
    vector <vector <pair <int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector <int> dis1(n, INT_MAX), vis1(n);
    priority_queue <pair <int, int>> pq;
    dis1[x] = 0;
    pq.push({0, x});
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (vis1[u]) continue;
        vis1[u] = 1;
        for (auto v : adj[u]) {
            int x = v.first, w = v.second;
            if (w + dis1[u] < dis1[x]) {
                dis1[x] = w + dis1[u];
                pq.push({-dis1[x], x});
            }
        }
    }
    if (dis1[y] <= z) {
        cout << y << ' ' << dis1[y] << ' ' << 0;
        return 0;
    }
    vector <int> dis2(n, INT_MAX), vis2(n);
    dis2[y] = 0;
    pq.push({0, y});
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (vis2[u]) continue;
        vis2[u] = 1;
        for (auto v : adj[u]) {
            int t = v.first, w = v.second;
            if (w + dis2[u] < dis2[t]) {
                dis2[t] = w + dis2[u];
                pq.push({-dis2[t], t});
            }
        }
    }
    priority_queue <pair <int, int>> q;
    for (int i = 0; i < n; i++) q.push({-dis2[i], -i});
    while (!q.empty()) {
        int t = -q.top().first, w = -q.top().second;
        q.pop();
        if (dis1[w] <= z) {cout << w << ' ' << dis1[w] << ' ' << t; return 0;}
    }
}
