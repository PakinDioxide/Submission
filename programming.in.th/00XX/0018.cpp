#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> alr(n+1);

    int c = 0, j = 2;
    while (1) {
        if (!alr[j]) {
            for (int i = j; i <= n; i += j) {
                if (!alr[i]) {
                    c++;
                    alr[i] = 1;
                    if (c == k) {
                        cout << i;
                        return 0;
                    }
                }
            }
        }
        j++;
    }
    return 0;
}
