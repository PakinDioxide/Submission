#include <bits/stdc++.h>

using namespace std;

int main() {
    float cake = 0;
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        cake += a + 0.75*b + 0.5*c + 0.25*d + 0.125*e;
    }

    cout << ceil(cake);
}
