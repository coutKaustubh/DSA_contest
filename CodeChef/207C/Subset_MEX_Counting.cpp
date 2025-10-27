#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f(i,n) for (ll i = 0; i < n; i++)
#define ia(a,n) ll a[n]; f(i,n) cin >> a[i]
#define iv(v,n) vector<ll> v(n); f(i,n) cin >> v[i]
#define create_matrix(mat, n, m) vector<vector<ll>> mat(n, vector<ll>(m))
#define input_matrix(mat, n, m) f(i,n) f(j,m) cin >> mat[i][j]
#define MOD 998244353
#define INF 1000000000000000000LL
#define mp make_pair
#define nline '\n'
#define yes cout << "Yes\n"
#define no cout << "No\n"




ll modpow(ll a, ll e) {
    ll r = 1;
    while (e) {
        if (e & 1) r = (r * a) % MOD;
        a = (a * a) % MOD;
        e >>= 1;
    }
    return r;
}




ll nCr(ll n, ll r, vector<ll>& fact, vector<ll>& ifact) {
    if (r < 0 || r > n) return 0;
    return fact[n] * ifact[r] % MOD * ifact[n - r] % MOD;
}

void solve() {
    ll n;
    cin >> n;

    
    static vector<ll> fact, ifact;
    static ll done = 0;

    ll lim = 2 * n + 5;
    if (!done) {
        fact.resize(lim);
        ifact.resize(lim);
        fact[0] = 1;
        for (ll i = 1; i < lim; i++) fact[i] = fact[i - 1] * i % MOD;
        ifact[lim - 1] = modpow(fact[lim - 1], MOD - 2);
        for (ll i = lim - 2; i >= 0; i--) ifact[i] = ifact[i + 1] * (i + 1) % MOD;
        done = 1;
    }

    ll comb2N_N = nCr(2 * n, n, fact, ifact);

    for (ll m = 1; m <= n; m++) {
        ll term1 = comb2N_N;
        ll term2 = nCr(2 * n - 1 - m, n, fact, ifact);
        ll term3 = nCr(n + m - 1, n, fact, ifact);
        ll ans = (term1 - term2 - term3) % MOD;
        if (ans < 0) ans += MOD;
        cout << ans;
        if (m < n) cout << ' ';
    }
    cout << nline;
}




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
