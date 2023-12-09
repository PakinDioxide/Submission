#include <bits/stdc++.h>

using namespace std;

long double p(long double a, int b) {
    long double res = 1;
    while (b > 0) {
        if (b%2 == 1) res *= a;
        a *= a;
        b /= 2;
    }

    return res;
}

int main() {
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        printf("%.0Lf\n", p(2.0L, a));
    }
}
