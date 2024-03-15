#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> a(n+1, INT_MAX);
    a[0] = 0;
    int k[4] = {1, 2, 5, 15}, w[4] = {500, 800, 1500, 3000};
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 4; j++) {
            if (k[j] <= i) {
                a[i] = min(a[i], a[i - k[j]] + w[j]);
            } else {
                a[i] = min(a[i], w[j]);
            }
        }
    }
    cout << a[n];
}
