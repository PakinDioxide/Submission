#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector <int> alr(n);

    int c = 0, j = 2;
    while (c != k) {
        for (int i = j; i <= n; i+=j) {
            if (!alr[i-1]) {
                c++;
                alr[i-1] = 1;
                if (c == k) {
                    cout << i;
                    return 0;
                }
            }
        }
        j++;
    }
}
