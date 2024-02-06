#include <bits/stdc++.h>

using namespace std;

long long ans = LLONG_MAX, n;
vector <int> a, b;

void sub(int i, long long aa, long long bb, int alr) {
    if (i == n) {
        if (!alr) return;
        long long h = abs(aa-bb);
        long long l = 0;
        for (int j = 1; j <= h; j++) l += j*j*j - j*j + j;
        ans = min(ans, l);
        return;
    }

    sub(i+1, aa, bb, alr == 1 ? 1 : 0);
    sub(i+1, aa+a[i], bb*b[i], 1);
}

int main() {
    cin >> n;
    a.resize(n);
    b.resize(n);

    for (int i = 0; i < n; i++) cin >> b[i] >> a[i];

    sub(0, 0, 1, 0);

    cout << ans;
}
