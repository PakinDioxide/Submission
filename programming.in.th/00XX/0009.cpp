#include <bits/stdc++.h>

using namespace std;

void swap(int *a, int *b) {
    int p;
    p = *a;
    *a = *b;
    *b = p;
}

int main() {
    int a, b, c;

    cin >> a >> b >> c;

    string q;
    cin >> q;

    if (a > b) swap(&a, &b);
    if (a > c) swap(&a, &c);
    if (b > c) swap(&b, &c);

    for (int i = 0; i < 3; i++) {
        if (q[i] == 'A') cout << a << ' ';
        else if (q[i] == 'B') cout << b << ' ';
        else cout << c << ' ';
    }
}
