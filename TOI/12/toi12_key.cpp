#include <bits/stdc++.h>

using namespace std;

string a, b, c;
map <pair <int, pair <int, int>>, bool> memo, vis;

bool solve (int k, int x, int y) {
    if (vis[{k, {x, y}}]) return memo[{k, {x, y}}];
    vis[{k, {x, y}}] = true;
    if (k == c.size()) return memo[{k, {x, y}}] = true;
    if (x < a.size() && c[k] == a[x]) {
        if (solve(k+1, x+1, y)) return memo[{k, {x, y}}] = true;
    }
    if (y < b.size() && c[k] == b[y]) {
        if (solve(k+1, x, y+1)) return memo[{k, {x, y}}] = true;
    }
    return memo[{k, {x, y}}] = false;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> a >> b;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c;
        if (solve(0, 0, 0)) cout << "Yes\n";
        else cout << "No\n";
        memo.clear();
        vis.clear();
    }
}
