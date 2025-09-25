#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f(i,n) for (ll i = 0; i < n; i++)
#define iv(v, n) vector<ll> v(n); f(i,n) cin >> v[i]

bool is_happy(ll c, vector<ll> &a) {
    bool has_less = false, has_equal = false;
    for (auto x : a) {
        if (x == c) has_equal = true;
        if (x < c) has_less = true;
    }
    return (!has_equal && has_less);
}

void solve() {
    ll n, c;
    cin >> n >> c;
    iv(a, n);

    ll extra = 0;
    while (!is_happy(c + extra, a)) {
        extra++;
    }

    cout << extra << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
