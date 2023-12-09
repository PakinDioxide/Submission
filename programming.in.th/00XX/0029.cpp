#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    cout << b/a + (b%a==0?0:1) + (a>b?1:0);
}
