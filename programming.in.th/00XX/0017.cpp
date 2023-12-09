#include <bits/stdc++.h>

using namespace std;

int main() {
    int side[4];
    for (int i = 0; i < 4; i++)  cin >> side[i];
    sort(side, side+4);

    cout << side[0] * side[2];
}
