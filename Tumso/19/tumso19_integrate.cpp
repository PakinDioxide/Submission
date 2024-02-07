#include <bits/stdc++.h>

using namespace std;

int main() {
    long long x, M = 1e9+7;
    cin >> x;
    cout << ((((x%M)*(x%M))%M)*(x%M))%M;
}
