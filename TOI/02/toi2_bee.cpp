#include <bits/stdc++.h>

using namespace std;

int main() {
    pair <int, int> a[25];

    a[0].first = 1;
    a[0].second = 2;

    for (int i = 1; i < 25; i++) {
        a[i].first = a[i-1].second;
        a[i].second = 1 + a[i].first + a[i-1].first;
    }

    int n;
    cin >> n;

    while (n != -1) {
        cout << a[n].first << ' ' << a[n].second << '\n';
        cin >> n;
    }
}
