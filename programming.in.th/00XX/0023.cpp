#include <bits/stdc++.h>

using namespace std;

int main() {
    int d[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string w[] = {"Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday"};

    int a, b;
    cin >> a >> b;

    for (int i = 0; i < b-1; i++) a += d[i];

    cout << w[(a-1)%7];
}
