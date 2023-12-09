#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    pair <int, int> a[n];

    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;

    float ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                float r = (float) abs(a[i].first*a[j].second + a[j].first*a[k].second + a[k].first*a[i].second - a[i].second*a[j].first - a[j].second*a[k].first - a[k].second*a[i].first) / 2;

                if (r > ans) ans = r;
            }
        }
    }

    printf("%.3f", ans);
}
