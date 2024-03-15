#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k = 1, c = 0;
    vector <bool> a(7400000);
    cin >> n;
    while (c < n) {
        k++;
        if (!a[k]) {
            for (int i = k; i < 7400000; i += k) a[i] = 1;
            c++;
        }
    }
    cout << k;
}
