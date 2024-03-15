#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int mi, co;
    double ans = DBL_MAX;
    for (int i = 1000; i <= 15000; i += 500) {
        double k = n + i*(100-(i-1000)/500);
        for (int j = 74; j <= 144; j++) {
            double in = j*(((100-(0.8569*exp((double)0.09*(j-100))))*i)/100);
            if (in > k && ans > in-k) {
                ans = in-k;
                mi = i;
                co = (int)j;
            }
        }
    }
    cout << mi << '\n' << co << '\n';
    printf("%.2lf", ans);
}
