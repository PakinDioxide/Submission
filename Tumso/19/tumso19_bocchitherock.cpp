#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector <vector<pair<int, long long>>> adj(n+1);

    for (int i = 0; i < m; i++) {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        adj[a+1].push_back({b+1, w});
        adj[b+1].push_back({a+1, w});
    }

    int k;
    cin >> k;

    for (int i = 0; i < k; i++) {
        int a;
        long long w;
        cin >> a >> w;
        adj[0].push_back({a+1, w});
    }

    vector <long long> dis(n+1, LLONG_MAX);
    vector <bool> vis(n+1);
    priority_queue <pair <long long, int>> q;
    dis[0] = 0;
    q.push({0, 0});

    while (!q.empty()) {
        int x = q.top().second;
        q.pop();
        if (vis[x]) continue;
        vis[x] = true;

        for (auto u : adj[x]) {
            int b = u.first;
            long long w = u.second;

            if (dis[x] + w < dis[b]) {
                dis[b] = dis[x] + w;
                q.push({-dis[b], b});
            }
        }
    }

    cout << dis[1];
}
