#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define tpl tuple<ll, ll, ll>
#define pll pair<ll, tpl>

ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

struct Hash {
    size_t operator()(const tpl &t) const {
        auto [x, y, z] = t;
        return hash<ll>()(x) ^ hash<ll>()(y << 1) ^ hash<ll>()(z << 2);
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        ll X, Y, Z, C;
        cin >> X >> Y >> Z >> C;

        unordered_set<tpl, Hash> visited;
        priority_queue<pll, vector<pll>, greater<pll>> pq;
        pq.push({0, {X, Y, Z}});

        ll limit = 20; 

        while (!pq.empty()) {
            auto [cost, state] = pq.top(); pq.pop();
            auto [x, y, z] = state;

            if (x == y) {
                cout << cost << "\n";
                break;
            }

            if (visited.count(state)) continue;
            visited.insert(state);

            
            if (z > 1 && z - 1 >= max(1LL, Z - limit))
                pq.push({cost + 1, {x, y, z - 1}});
            if (z + 1 <= Z + limit)
                pq.push({cost + 1, {x, y, z + 1}});

            ll gx = gcd(x, z), ly = lcm(y, z);
            if (gx <= 1e9 && ly <= 1e9)
                pq.push({cost + C, {gx, ly, z}});

            ll lx = lcm(x, z), gy = gcd(y, z);
            if (lx <= 1e9 && gy <= 1e9)
                pq.push({cost + C, {lx, gy, z}});
        }
    }
    return 0;
}
