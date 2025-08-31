#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int main() {
    int n, q;
    cin >> n;
    vector<LL> v(n + 1, 0), prefix_sum(n + 1, 0), dp(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        prefix_sum[i] = prefix_sum[i - 1] + v[i];
    }

    for (int i = 1; i <= n; ++i) {
        dp[i] = max(dp[i - 1], (prefix_sum[i] + i - 1) / i);
    }

    for (int i = 1; i <= n; ++i) {
        dp[i] = max(dp[i], (prefix_sum[n] + i - 1) / i);
    }

    reverse(dp.begin() + 1, dp.end());

    cin >> q;
    while (q--) {
        LL t;
        cin >> t;
        int idx = upper_bound(dp.begin() + 1, dp.end(), t) - dp.begin() - 1;
        idx = n - idx + 1;
        if (idx > n) cout << -1 << endl;
        else cout << idx << endl;
    }

    return 0;
}

