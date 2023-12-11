#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    string a[n];

    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++) {
        int s[] = {1,2,3,5,4,6};
        for (auto j : a[i]) {
            if (j == 'F') {
                swap(s[0], s[1]);
                swap(s[0], s[5]);
                swap(s[0], s[3]);
            } else if (j == 'B') {
                swap(s[0], s[3]);
                swap(s[0], s[5]);
                swap(s[0], s[1]);
            } else if (j == 'L') {
                swap(s[0], s[2]);
                swap(s[0], s[5]);
                swap(s[0], s[4]);
            } else if (j == 'R') {
                swap(s[0], s[4]);
                swap(s[0], s[5]);
                swap(s[0], s[2]);
            } else if (j == 'C') {
                swap(s[1], s[2]);
                swap(s[1], s[3]);
                swap(s[1], s[4]);
            } else if (j == 'D') {
                swap(s[1], s[4]);
                swap(s[1], s[3]);
                swap(s[1], s[2]);
            }
        }
        cout << s[1] << ' ';
    }
}
