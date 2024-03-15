#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, k = 1, j = 1, c = 0;
    cin >> n >> m;
    vector <bool> a(n+1);
    while (c != n) {
        if (k > m) k = 1;
        if (j > n) j = 1;
        if (a[j]) {j++; continue;}
        if (k == m) {cout << j << ' '; a[j] = 1; c++;}
        k++;
        j++;
    }
}
