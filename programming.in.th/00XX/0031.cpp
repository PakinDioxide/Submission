#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int ans = 0;
    while (a!=1) {ans++; a/=2;}
    while (b!=1) {ans++; b/=2;}
    while (c!=1) {ans++; c/=2;}
    cout << ans;
}
