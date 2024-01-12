#include <bits/stdc++.h>

using namespace std;

long long ans = LLONG_MAX, n;
vector <int> s, b;

void sub(int i, long long ss, long long bb, int alr) {
    if (i == n) {
        if (!alr) return;
        long long h = abs(ss-bb);
        long long l = 0;
        for (int j = 1; j <= h; j++) l += j*j*j - j*j + j;
        ans = min(ans, l);
        return;
    }

    sub(i+1, ss, bb, alr == 1 ? 1 : 0);
    sub(i+1, ss+s[i], bb*b[i], 1);
}

int main() {
    cin >> n;
    s.resize(n);
    b.resize(n);

    for (int i = 0; i < n; i++) cin >> b[i] >> s[i];

    sub(0, 0, 1, 0);

    cout << ans;
}
