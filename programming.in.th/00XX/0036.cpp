#include <bits/stdc++.h>

using namespace std;

long long nCr(int n, int r) {
    long long res = 1;

    for (int i = n; i > n-r; i--) res *= i;
    for (int i = r; i > 1; i--) res /= i;

    return res;
}

int main() {
    int n;
    cin >> n;

    cout << (n&1 == 1 ? 2*nCr(n, n/2) : nCr(n, n/2)) << '\n';
}
