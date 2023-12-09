#include <bits/stdc++.h>

using namespace std;

int main() {

    int a = 0, b;

    for (int i = 0; i < 5; i++) {
        int w, x, y, z;
        cin >> w >> x >> y >> z;
        if (a < w+x+y+z) {
            a = w+x+y+z;
            b = i+1;
        }
    }

    cout << b << " " << a;
}
