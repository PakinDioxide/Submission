#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, k;
    cin >> n >> k;
    int a[n], p[n+1];
    p[0] = 0;
    for (int i = 0; i < n; i++) {cin >> a[i]; p[i+1] = a[i] + p[i];}
    deque <pair <int, int>> dq;
    for (int i = 1; i <= n; i++) {
        while (!dq.empty() && dq.front().second < i-k) dq.pop_front();
        p[i] = a[i-1];
        if (!dq.empty()) p[i] += dq.front().first;
        while (!dq.empty() && dq.back().first > p[i]) dq.pop_back();
        dq.push_back({p[i], i});
    }
    cout << p[n];
}
