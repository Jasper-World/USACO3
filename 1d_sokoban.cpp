#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define N 200005
int n, m;
int input[N], a1[N], b1[N], a2[N], b2[N], cnt11, cnt12, cnt21, cnt22;
map<int, int> mp;

int solve(int a[], int b[], int lena, int lenb)
{
    int res = 0;
    mp.clear();
    int mh = 0;
    for (int i = 1; i <= lena; i++) mp[a[i]] = 1;
    for (int i = 1; i <= lenb; i++) if (mp[b[i]] == 1) mh++;

    res = mh;
    for (int i = 1; i <= lenb; i++)
    {
        if (mp[b[i]] == 1)
        {
            mh--;
            continue;
        }
        int sum = upper_bound(a + 1, a + 1 + lena, b[i]) - a - 1;
        int pos = lower_bound(b + 1, b + 1 + lenb, b[i] - sum + 1) - b;
        res = max(res, mh + i - pos + 1);
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Case = 1;
    cin >> Case;
    while (Case--)
    {
        cnt11 = cnt12 = cnt21 = cnt22 = 0;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            cin >> input[i];
            if (input[i] > 0) a1[++cnt11] = input[i];
        }
        for (int i = n; i >= 1; i--)
        {
            if (input[i] < 0) a2[++cnt12] = -1 * input[i];
        }
        for (int i = 1; i <= m; i++)
        {
            cin >> input[i];
            if (input[i] > 0) b1[++cnt21] = input[i];
        }
        for (int i = m; i >= 1; i--)
        {
            if (input[i] < 0) b2[++cnt22] = -1 * input[i];
        }
        int ans = 0;
        ans += solve(a1, b1, cnt11, cnt21);
        ans += solve(a2, b2, cnt12, cnt22);
        cout << ans << "\n";
    }
    return 0;
}

