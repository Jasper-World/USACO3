#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> pos(27), id(n + 1);
    vector<char> val(27);
    int cnt = 0;

    for (int i = 1; i <= n; i++) {
        cout << "? 2 1 " << i << endl;
        int now;
        cin >> now;
        if (cnt != now) {
            ++cnt;
            id[i] = cnt;
            pos[cnt] = i;
        } else {
            static int a[27];
            for (int j = 1; j <= cnt; j++) a[j] = pos[j];
            sort(a + 1, a + cnt + 1);
            int l = 2, r = cnt, res = 1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                cout << "? 2 " << a[mid] << " " << i << endl;
                cin >> now;
                if (now == cnt - mid + 1) res = mid, l = mid + 1;
                else r = mid - 1;
            }
            for (int j = 1; j <= cnt; j++) {
                if (a[res] == pos[j]) {
                    id[i] = j;
                    pos[j] = i;
                }
            }
        }
    }

    for (int i = 1; i <= cnt; i++) {
        cout << "? 1 " << pos[i] << endl;
        cin >> val[i];
    }

    cout << "! ";
    for (int i = 1; i <= n; i++) cout << val[id[i]];
    cout << endl;

    return 0;
}

