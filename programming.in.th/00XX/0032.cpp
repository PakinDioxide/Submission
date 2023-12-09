#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector <int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());
    int alr = 0;

    while (!a.empty()) {
        if (!alr) {
            for (int i = 0; i < n; i++) {
                if (a[i] != 0) {
                    cout << a[i];
                    a.erase(a.begin()+i);
                    alr = 1;
                    break;
                }
            }
        } else {
            cout << a[0];
            a.erase(a.begin());
        }
    }
}
