#include <bits/stdc++.h>
using namespace std;

vector<int> to_reduced_list(string s) {
    vector<int> l;
    for (char ch : s) {
        int c = ch - '0';
        if (!l.empty() && l.back() == c) continue;
        l.push_back(c);
    }
    return l;
}

void solve() {
    int N, P;
    cin >> N >> P;

    vector<vector<int>> tubes(3);
    for (int i = 0; i < 2; i++) {
        string s;
        cin >> s;
        tubes[i] = to_reduced_list(s);
    }

    if (tubes[0][0] == tubes[1][0]) {
        tubes[0].insert(tubes[0].begin(), tubes[0][0] ^ 3);
    }

    int ans = (int)tubes[0].size() + (int)tubes[1].size() - 2;
    if (ans > 1) ans += 1;

    cout << ans << "\n";
    if (P == 1) return;

    vector<pair<int,int>> moves;

    auto move = [&](int src, int dst) {
        moves.push_back({src, dst});
        if (tubes[dst].empty() || tubes[dst].back() != tubes[src].back()) {
            tubes[dst].push_back(tubes[src].back());
        }
        tubes[src].pop_back();
    };

    if (!tubes[0].empty() && !tubes[1].empty() && tubes[0].back() == tubes[1].back()) {
        if (tubes[0].size() > tubes[1].size()) move(0, 1);
        else move(1, 0);
    }

    for (int i = 0; i < 2; i++) {
        if (tubes[i].size() > 1) {
            move(i, 2);
            int idx_to_empty = 0;
            if (!tubes[2].empty() && tubes[idx_to_empty][0] == tubes[2][0]) idx_to_empty ^= 1;

            while (tubes[idx_to_empty].size() > 1) {
                if (!tubes[2].empty() && tubes[idx_to_empty].back() == tubes[2][0]) {
                    move(idx_to_empty, 2);
                } else {
                    move(idx_to_empty, idx_to_empty ^ 1);
                }
            }

            idx_to_empty ^= 1;
            while (tubes[idx_to_empty].size() > 1) {
                if (!tubes[2].empty() && tubes[idx_to_empty].back() == tubes[2][0]) {
                    move(idx_to_empty, 2);
                } else {
                    move(idx_to_empty, idx_to_empty ^ 1);
                }
            }
            move(2, idx_to_empty);
            break;
        }
    }

    assert((int)moves.size() == ans);
    for (auto [a, b] : moves) {
        cout << a + 1 << " " << b + 1 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
}

