#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        long long x;
        cin >> x;
        if (x == 1 || x == 2) cout << "NO\n";
        else cout << (x-3)%1000000007 << '\n';
    }
}
