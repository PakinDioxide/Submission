#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int a, b, p, ca = 0, cb = 0, ans;
    cin >> p;
    a = p;
    b = p;
    for (int i = 0; i < 2*p; i++) {
        if (a <= 0 || b <= 0) break;
        int k;
        cin >> k;
        ans = k;
        if (k&1) {
            cb = 0;
            ca++;
            if (ca > 2) b -= 3;
            else b--;
        } else {
            ca = 0;
            cb++;
            if (cb > 2) a -= 3;
            else a--;
        }
    }
    cout << (a <= 0 ? 0 : 1) << '\n' << ans;
}
