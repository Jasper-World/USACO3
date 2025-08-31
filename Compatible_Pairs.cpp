#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll a, b;
    cin >> n >> a >> b;

    map<ll, ll> cowCount;
    for (int i = 0; i < n; i++) {
        ll count, id;
        cin >> count >> id;
        cowCount[id] = count;
    }

    map<ll, set<ll>> neighbors;
    vector<ll> checkList;

    for (auto &entry : cowCount) {
        ll id = entry.first;
        neighbors[id] = {};
    }

    for (auto &entry : cowCount) {
        ll id = entry.first;
        for (ll targetSum : {a, b}) {
            ll partnerId = targetSum - id;
            if (cowCount.count(partnerId)) {
                neighbors[id].insert(partnerId);
            }
        }
    }

    for (auto &entry : cowCount) {
        checkList.push_back(entry.first);
    }

    ll maxPairs = 0;

    while (!checkList.empty()) {
        ll currentId = checkList.back();
        checkList.pop_back();

        if (neighbors[currentId].size() != 1) continue;

        ll partnerId = *neighbors[currentId].begin();
        if (currentId == partnerId) {
            maxPairs += cowCount[currentId] / 2;
        } else {
            ll pairsFormed = min(cowCount[currentId], cowCount[partnerId]);
            maxPairs += pairsFormed;
            cowCount[partnerId] -= pairsFormed;
        }

        neighbors[currentId].erase(partnerId);
        neighbors[partnerId].erase(currentId);
        checkList.push_back(partnerId);
    }

    cout << maxPairs << "\n";
    return 0;
}

