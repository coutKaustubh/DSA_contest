#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    const ll NEG = -(1LL << 60);
    vector<ll> dp(n + 5, NEG);

    for (int p = n - 1; p >= 0; p--) {
        ll best = NEG;

        {
            ll leaf = a[p];
            if (p == n - 1) {
                best = max(best, leaf);
            } else if (p + 2 <= n - 1 && dp[p + 2] != NEG) {
                best = max(best, min(leaf, dp[p + 2]));
            }
        }

        if (p + 1 < n) {
            ll leaf = max(a[p], a[p + 1]);
            if (p + 1 == n - 1) {
                best = max(best, leaf);
            } else if (p + 3 <= n - 1 && dp[p + 3] != NEG) {
                best = max(best, min(leaf, dp[p + 3]));
            }
        }

        dp[p] = best;
    }

    cout << dp[0] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
       solve();
    }
    return 0;
}