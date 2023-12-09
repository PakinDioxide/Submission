#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int m = 0, l = 0, r = 1;
    vector <int> ans;

    while (r <= n) {
        if (r == n || a[l] != a[r]) {
            if (m < r-l) {
                ans.clear();
                ans.push_back(a[l]);
                m = r-l;
            } else if (m == r-l) {
                ans.push_back(a[l]);
            }
            l = r;
        }
        r++;
    }

    for (auto i : ans) cout << i << " ";
}
