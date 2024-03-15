#include <bits/stdc++.h>

using namespace std;

int main() {
    int l, k;
    cin >> l >> k;
    string a, b, x;
    cin >> a >> b >> x;

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < l; j++) {
            char l[3] = {x[i], a[j], b[j]};
            sort(l, l+3);
            x[i] = l[1];
        }
    }
    cout << x;
}
