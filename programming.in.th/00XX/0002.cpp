#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int mi = INT_MAX, ma = INT_MIN;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        mi = min(mi, a);
        ma = max(ma, a);
    }

    cout << mi << "\n" << ma;
}
