#include <bits/stdc++.h>

using namespace std;

int n, m, x, y, z, a[10][3], b[10][3], ans = INT_MAX;
vector <bool> vis(10);

int dis(int aa, int bb, int cc, int xx, int yy, int zz) {
    return (aa-xx)*(aa-xx) + (bb-yy)*(bb-yy) + (cc-zz)*(cc-zz);
}

void solve(int p, int q, int r, int t, int u, int v, int cost) {
    if (min({t, u, v}) >= n) {ans = min(cost, ans); return;}
    for (int i = 0; i < m; i++) {
        if (!vis[i]) {
            vis[i] = true;
            solve(a[i][0], a[i][1], a[i][2], t+b[i][0], u+b[i][1], v+b[i][2], cost+dis(p,q,r,a[i][0],a[i][1],a[i][2]));
            vis[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> x >> y >> z >> m;
    for (int i = 0; i < m; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2] >> b[i][0] >> b[i][1] >> b[i][2];
    }
    solve(x, y, z, 0, 0, 0, 0);
    cout << ans;
}
