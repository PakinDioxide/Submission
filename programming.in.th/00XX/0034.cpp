#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int w, x, y, z;

    for (w = 1; w <= (int)sqrt(a); w++) {
        if (a % w == 0) {
            for (x = -abs(c); x <= abs(c); x++) {
                if (x != 0 && c % x == 0) {
                    y = a/w;
                    z = c/x;
                    if (w*z + x*y == b) {
                        cout << w << " " << x << " " << y << " " << z;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "No Solution";
}
