#include <bits/stdc++.h>

using namespace std;

int ans = INT_MAX, n;
vector <int> s, b;

void sub(int i, int ss, int bb, int alr) {
    if (i == n) {
        if (abs(ss-bb) < ans && alr) ans = abs(ss-bb);
        return;
    }

    sub(i+1, ss, bb, alr == 1 ? 1 : 0);
    sub(i+1, ss*s[i], bb+b[i], 1);
}

int main() {
    cin >> n;
    s.resize(n);
    b.resize(n);

    for (int i = 0; i < n; i++) cin >> s[i] >> b[i];

    sub(0, 1, 0, 0);

    cout << ans;
}
