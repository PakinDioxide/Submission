#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;

int n, m, par[200001];
priority_queue <pair <int, pair <int, int>>> adj;

int fin(int x) {
    if (par[x] != x) par[x] = fin(par[x]);
    return par[x];
}

void un(int x, int y) {
    par[fin(x)] = fin(y);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) par[i] = i;
    for (int i = 0; i < m; i++ ){
        pair <int, pair <int, int>> k;
        cin >> k.s.f >> k.s.s >> k.f;
        k.f--;
        adj.push(k);
    }
    long long c = 0, ans = 0;

    while (!adj.empty() && c < n-1) {
        int x = adj.top().s.f, y = adj.top().s.s, z = adj.top().f;
        if (fin(x) != fin(y)) {
            c++;
            ans += z;
            un(x, y);
        }
        adj.pop();
    }
    cout << ans;
}
