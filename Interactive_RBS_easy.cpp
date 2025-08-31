#include <bits/stdc++.h>
using namespace std;
#define ll long long

void fio() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    fio();
    ll t;
    cin >> t;
    while (t--) {
        ll n; 
        cin >> n;
        ll a1, a2;
        auto q1 = [&](ll x) {
            cout << "? " << x;
            for (ll i = 1; i <= x; i++) cout << " " << i;
            cout << endl;
            cout.flush();
            ll res; cin >> res;
            return res;
        };
        auto q2 = [&](ll x) {
            cout << "? " << n - x + 1;
            for (ll i = x; i <= n; i++) cout << " " << i;
            cout << endl;
            cout.flush();
            ll res; cin >> res;
            return res;
        };

        ll l = 2, r = n;
        while (l < r) {
            ll mid = (l + r) >> 1;
            if (q1(mid)) r = mid;
            else l = mid + 1;
        }
        if (q1(r)) a1 = r;
        else a1 = 1;

        l = 1, r = n - 1;
        while (l <= r) {
            ll mid = (l + r) >> 1;
            if (q2(mid)) l = mid + 1;
            else r = mid - 1;
        }
        if (r == 0) r = 1;
        if (q2(r)) a2 = r;
        else a2 = n;

        swap(a1, a2);

        vector<char> a(n + 2);

        for (ll i = 2; i <= n; i += 2) {
            cout << "? 8 " << a1 << " " << a1 << " " << a1 << " " << a2 
                 << " " << a1 << " " << a2 << " " << i - 1 << " " << i << endl;
            cout.flush();
            ll x; cin >> x;
            if (x == 6) a[i - 1] = '(', a[i] = ')';
            else if (x == 4) a[i - 1] = ')', a[i] = '(';
            else if (x == 3) a[i - 1] = '(', a[i] = '(';
            else a[i - 1] = ')', a[i] = ')';
        }

        if (n & 1) {
            cout << "? 2 " << n << " " << a2 << endl;
            cout.flush();
            ll x; cin >> x;
            if (x > 0) a[n] = '(';
            else a[n] = ')';
        }

        cout << "! ";
        for (ll i = 1; i <= n; i++) cout << a[i];
        cout << endl;
    }
    return 0;
}

