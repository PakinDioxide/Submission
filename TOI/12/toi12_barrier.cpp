#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    int p[n+1];
    p[0] = 0;
    for (int i = 0; i < n; i++) {cin >> p[i+1]; p[i+1] += p[i];}
    int ans = 0, l = INT_MAX;
    deque <pair <int, int>> q;
    for (int i = 1; i <= n; i++) {
        while (!q.empty() && q.front().second < i-m) q.pop_front();
        while (!q.empty() && q.back().first >= p[i]) q.pop_back();
        q.push_back({p[i], i});
        if (ans < p[i] - q.front().first) {
            ans = p[i] - q.front().first;
            l = i - q.front().second;
        } else if (ans == p[i] - q.front().first) {
            l = min(l, i - q.front().second);
        }
    }
    cout << ans <<  '\n' << (ans == 0 ? 0 : l);
}