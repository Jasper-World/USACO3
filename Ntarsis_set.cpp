#include<bits/stdc++.h>

using namespace std;
using LL = long long;

const int N = 2e5 + 5;

LL a[N];

inline void solve() {
    LL n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    LL j = 0, ans = 1;
    while (k--) {
        while (j < n && a[j] <= ans + j) j++;
        ans += j;
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
}
