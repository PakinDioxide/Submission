#include <bits/stdc++.h>

using namespace std;

int n;
long long a[500000], b[500000];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    sort(a, a+n);
    sort(b, b+n);
    for (int i = 0; i < n; i++) a[i] += b[n-i-1];
    sort(a, a+n);
    cout << a[n-1] - a[0];
}
