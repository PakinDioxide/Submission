#include <bits/stdc++.h>

using namespace std;

int main() {
    int w, h, n;
    cin >> w >> h >> n;

    vector <int> a(w);

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        for (int j = x; j < x+y && j < w; j++) a[j]++;
    }

    int o = 0, p = 0;

    for (int i = 0; i < w; i++) {
        if (a[i] == 0) o += h;
        else if (a[i] == 1) p += h;
    }

    cout << o << ' ' << p;
}
