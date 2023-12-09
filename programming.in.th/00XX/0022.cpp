#include <bits/stdc++.h>

using namespace std;

int main() {
    int r;

    cin >> r;

    int w = r - 1 + (r%2);

    for (int i = 1; i <= r; i++) {
        int k = abs(r/2+r%2-i);
        if (i > r/2 && r%2 == 0) k--;

        for (int j = 0; j < k; j++) cout << '-';
        cout << '*';
        for (int j = 0; j < w-2-2*k; j++) cout << '-';
        if (i != 1 && i != r) cout << '*';
        for (int j = 0; j < k; j++) cout << '-';

        if (i == r/2 && r%2 == 0) {
            cout << '\n';
            for (int j = 0; j < k; j++) cout << '-';
            cout << '*';
            for (int j = 0; j < w-2-2*k; j++) cout << '-';
            if (i != 1 && i != r) cout << '*';
            for (int j = 0; j < k; j++) cout << '-';
            i++;
        }

        cout << '\n';
    }
}
