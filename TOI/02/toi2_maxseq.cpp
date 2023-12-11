#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int a[n];

    int sum = 0, ans = 0;

    for (int i = 0; i < n; i++) cin >> a[i];

    int f = 0, l = 0, fa, la;

    for (int i = 0; i < n; i++) {
        if (sum + a[i] > a[i]) {l = i; sum += a[i];}
        else {f = l = i; sum = a[i];}
        if (ans < sum) {ans = sum; fa = f; la = l;}
    }

    if (ans == 0) cout << "Empty sequence";
    else {
        for (int i = fa; i <= la; i++) cout << a[i] << ' ';
        cout << '\n' << ans;
    }
}
