#include <bits/stdc++.h>



using namespace std;


#define ll long long
#define f(i,n) for (ll i = 0; i < n; i++)
#define ia(a,n) \
    ll a[n];     \
    f(i,n) cin >> a[i]
#define iv(v, n)     \
    vector<ll> v(n); \
    f(i,n) cin >> v[i]

#define create_matrix(mat, n, m) vector<vector<ll>> mat(n, vector<ll>(m));
#define input_matrix(mat, n, m) f(i,n) f(j,m) cin >> mat[i][j];

    
#define INF 1000000000000000000LL // Infinity for ll
#define mp make_pair
#define nline '\n'
#define yes cout << "Yes\n"
#define no cout << "No\n"

const ll MOD (1000000007);




void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> p(n);
    f(i,n){
        p[i]=i;
    }

    if (k == 0) {
        ll ans = (n * (n + 1) / 2) % MOD;
        cout << ans << "\n";
        return;
    }
    if (k > n) {
        cout << 0 << "\n";
        return;
    }

    vector<ll> pos(n);
    for (int i = 0; i < n; i++) pos[p[i]] = i;

    ll L = n, R = -1;
    for (int i = 0; i < k; i++) {
        L = min(L, pos[i]);
        R = max(R, pos[i]);
    }

    ll posK = pos[k];
    ll ans = 0;

    auto mulmod = [&](ll a, ll b) {
        return ((a % MOD) * (b % MOD)) % MOD;
    };

    if (posK < L) {
        ans = mulmod((L - posK), (n - R));
    } else if (posK > R) {
        ans = mulmod((R - L + 1), (posK - R));
    } else {
        ans = 0;
    }

    cout << ans % MOD << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) solve();
}
