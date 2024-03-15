#include <bits/stdc++.h>

using namespace std;

bool check(const pair <int,int> &a, const pair <int,int> &b) {
    if (a.first == b.first) return b.second > a.second;
    return a.first > b.first;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <pair <int, int>> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end(), check);
    vector <pair <int, int>> b;
    int m = -1;
    for (int i = 0; i < n; i++) {
        if (m <= a[i].second) {
            m = a[i].second;
            b.push_back({a[i].first, a[i].second});
        }
    }
    for (auto i : b) cout << i.first << ' ' << i.second << '\n';
}
