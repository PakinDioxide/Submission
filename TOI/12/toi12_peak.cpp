#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, k;
    cin >> n >> k;
    priority_queue <int> s;
    int a[n+2];
    a[0] = -1;
    a[n+1] = -1;
    for (int i = 1; i <= n+1; i++) {
        if (i <= n) cin >> a[i];
        if (i > 1 && a[i-1] > a[i-2] && a[i-1] > a[i]) s.push(a[i-1]);
    }
    if (s.empty()) {
        cout << -1;
        return 0;
    }
    vector <int> s2;
    int r = -1, c = 0;
    while (!s.empty() && c < k) {
        if (s.top() != r) {
            s2.push_back(s.top());
            r = s.top();
            c++;
        }
        s.pop();
    }
    if (s2.size() >= k) for (auto i : s2) cout << i << '\n';
    else for (int i = s2.size()-1; i >= 0; i--) cout << s2[i] << '\n';
}