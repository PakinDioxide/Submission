#include <bits/stdc++.h>

using namespace std;

char solve() {
    long long n, r, d;
    cin >> n >> r >> d;
    pair <long long, long long> p[n];
    for (int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;
    sort(p, p+n);
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (p[j].first - p[i].first >= 2*r+d || p[j].second - p[i].second >= 2*r+d) break;
            if (sqrt((p[i].first - p[j].first)*(p[i].first - p[j].first)+(p[i].second - p[j].second)*(p[i].second - p[j].second))-2*r < d) return 'N';
        }
    }
    return 'Y';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cout << solve() << '\n';
}