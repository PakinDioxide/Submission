#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair <int, int>
#define f first
#define s second

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll n, m;
    cin >> m >> n;
    pair <pii, ll> a[2*m];
    for (int i = 0; i < m; i++) {
        cin >> a[2*i].f.s >> a[2*i].f.f >> a[2*i+1].f.f;
        a[2*i].s = 0;
        a[2*i+1].s = 1;
        a[2*i+1].f.s = a[2*i].f.s;
        a[2*i+1].f.f++;
    }
    sort(a, a+2*m);
    ll ans = 0, ca = 0, c[11];
    for (int i = 0; i <= 10; i++) c[i] = 1;
    for (int i = 0; i < 2*m; i++) {
        if (a[i].s == 0) {
            switch(a[i].f.s) {
                case 2 : c[2]++; break;
                case 3 : c[3]++; break;
                case 4 : c[2] += 2; break;
                case 5 : c[5]++; break;
                case 6 : c[2]++; c[3]++; break;
                case 7 : c[7]++; break;
                case 8 : c[2] += 3; break;
                case 9 : c[3] += 2; break;
                case 10 : c[2]++; c[5]++; break;
            }
        } else {
            switch(a[i].f.s) {
                case 2 : c[2]--; break;
                case 3 : c[3]--; break;
                case 4 : c[2] -= 2; break;
                case 5 : c[5]--; break;
                case 6 : c[2]--; c[3]--; break;
                case 7 : c[7]--; break;
                case 8 : c[2] -= 3; break;
                case 9 : c[3] -= 2; break;
                case 10 : c[2]--; c[5]--; break;
            }
        }
        if (i == 2*m-1 || a[i].f.f != a[i+1].f.f) {
            ll kk = 1;
            for (int j = 2; j <= 7; j++) kk *= c[j];
            if (ans < kk) {ans = kk; ca = a[i+1].f.f - a[i].f.f;}
            else if (ans == kk) ca += a[i+1].f.f - a[i].f.f;
        }
    }
    cout << ans << ' ' << ca;
}