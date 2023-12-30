#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n][n];
    vector <bool> alr(n*n+1);
    bool ok = true;
    int ss = 0;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            sum += a[i][j];
            if (alr[a[i][j]] == false) alr[a[i][j]] = true;
            else ok = false;
        }
        if (i == 0) ss = sum;
        else if (ss != sum) ok = false;
    }

    int s1 = 0, s2 = 0;

    for (int i = 0; i < n; i++) {
        s1 += a[i][i];
        s2 += a[i][n-i-1];
    }

    if (s1 != s2 || s1 != ss) ok = false;

    if (ok) cout << "Yes";
    else cout << "No";
}
