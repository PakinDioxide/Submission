#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    for (int i = 0; i < 20; i++) {
        int x, y;
        cin >> x >> y;
        if ((4*y-x)/2 > y || (4*y-x) < 0) cout << "0\n";
        else cout << (4*y-x)/2+1 << '\n';
    }
}