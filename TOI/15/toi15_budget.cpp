#include <bits/stdc++.h>

using namespace std;

int n, m;
int par[5000];

int fin(int x) {
    if (par[x] != x) par[x] = fin(par[x]);
    return par[x];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) par[i] = i;
    priority_queue <pair <long long, pair <int, int>>> edge;
    for (int i = 0; i < m; i++) {
        int w, x, y, z;
        cin >> w >> x >> y >> z;
        if (z) par[fin(w)] = fin(x);
        else {
            edge.push({-y, {w, x}});
        }
    }
    int p;
    cin >> p;
    vector <pair <long long, long long>> pri;
    for (int i = 0; i < p; i++) {
        long long x, y;
        cin >> x >> y;
        pri.push_back({x, -y});
    }
    sort(pri.begin(), pri.end());
    for (int i = p-1; i > 0; i--) if (pri[i].second > pri[i-1].second) pri[i-1].second = pri[i].second;
    long long ans = 0;
    while (!edge.empty()) {
        long long x = edge.top().second.first, y = edge.top().second.second, z = -edge.top().first;
        edge.pop();
        if (fin(x) != fin(y)) {
            int idx = lower_bound(pri.begin(), pri.end(), make_pair(z, (long long)0)) - pri.begin();
            if (idx == p) continue;
            par[fin(x)] = fin(y);
            ans -= pri[idx].second;
        }
    }
    cout << ans;
}