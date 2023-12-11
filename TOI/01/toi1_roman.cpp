#include <bits/stdc++.h>

using namespace std;

int main() {
    int i, v, x, l, c, n;
    i = v = x = l = c = 0;

    cin >> n;

    for (int j = 1; j <= n; j++) {
        int k = j;
        if (k >= 100) {
            c += k/100;
            k %= 100;
        }
        if (k >= 90) {
            x++;
            c++;
            k -= 90;
        }
        if (k >= 50) {
            l += k/50;
            k %= 50;
        }
        if (k >= 40) {
            x++;
            l++;
            k -= 40;
        }
        if (k >= 10) {
            x += k/10;
            k %= 10;
        }
        if (k >= 9) {
            i++;
            x++;
            k -= 9;
        }
        if (k >= 5) {
            v += k/5;
            k %= 5;
        }
        if (k >= 4) {
            i++;
            v++;
            k -= 4;
        }
        i += k;
    }

    cout << i << " " << v << " " << x << " " << l << " " << c;
}
