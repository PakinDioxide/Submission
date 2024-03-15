#include <bits/stdc++.h>

using namespace std;

int main() {
    unsigned int n, k, m = 0, a[30001];
    cin >> n >> k;
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        m = max(m, unsigned(upper_bound(a+1, a+n+1, a[i]+k) - a - i - 1));
    }
    cout << m;
}
