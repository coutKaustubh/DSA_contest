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

#define MOD (998244353LL)
#define INF 1000000000000000000LL 
#define mp make_pair
#define nline '\n'
#define yes cout << "Yes\n"
#define no cout << "No\n"

vector<ll> fact_, ifact_;
 
ll modpow(ll a, ll e) {
    ll r = 1 % MOD;
    while (e) {
        if (e & 1) r = (r * a) % MOD;
        a = (a * a) % MOD;
        e >>= 1;
    }
    return r;
}
 
void precompute_fact(int nmax) {
    fact_.assign(nmax + 1, 1);
    ifact_.assign(nmax + 1, 1);
    for (int i = 1; i <= nmax; ++i) fact_[i] = fact_[i-1] * i % MOD;
    ifact_[nmax] = modpow(fact_[nmax], MOD-2);
    for (int i = nmax; i >= 1; --i) ifact_[i-1] = ifact_[i] * i % MOD;
}
 
ll C(ll n, ll k) {
    if (k < 0 || k > n || n < 0) return 0;
    return fact_[n] * ifact_[k] % MOD * ifact_[n-k] % MOD;
}

ll count_for_N(ll N) {
    
    ll c0 = N / 3;
    ll remN = N % 3;
    ll c1 = N / 3 + (remN >= 1 ? 1 : 0);
    ll c2 = N / 3 + (remN >= 2 ? 1 : 0);
    
    
    if (c1 == 0 && c2 == 0) {
        if (c0 <= 1) return fact_[c0] % MOD;
        return 0;
    }
 
    ll ans = 0;
    
    for (ll R = max(1LL, c0 - 1); R <= c0 + 1; ++R) {
        
        if (R > c1 + c2) continue;
        
        ll needed_internal = R - 1;
        if (needed_internal > c0) continue;
        ll rem = c0 - needed_internal;
        if (rem < 0 || rem > 2) continue; 
 
        
        for (int start = 0; start < 2; ++start) {
            ll r1, r2;
            if (start == 0) {
                
                r1 = (R + 1) / 2; 
                r2 = R - r1;
            } else {
                
                r1 = R / 2;       
                r2 = R - r1;
            }
            if (r1 < 0 || r2 < 0) continue;
            if (r1 > c1 || r2 > c2) continue;
            
            ll ways1 = 1, ways2 = 1;
            if (r1 == 0) {
                if (c1 != 0) continue;
                ways1 = 1;
            } else {
                ways1 = C(c1 - 1, r1 - 1);
            }
            if (r2 == 0) {
                if (c2 != 0) continue;
                ways2 = 1;
            } else {
                ways2 = C(c2 - 1, r2 - 1);
            }
            
            ll ways_zero_ends = C(2, rem);
            ll ways_residue_structure = ways1 * ways2 % MOD * ways_zero_ends % MOD;
            
            ll ways_labels = fact_[c0] * fact_[c1] % MOD * fact_[c2] % MOD;
            ll add = ways_residue_structure * ways_labels % MOD;
            ans += add;
            if (ans >= MOD) ans -= MOD;
        }
    }
    return ans % MOD;
}

void solve(){
    ll n;
    cin >> n;
    cout << count_for_N(n) << nline;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    vector<int> Ns(T);
    int maxN = 0;
    for (int i = 0; i < T; ++i) {
        cin >> Ns[i];
        if (Ns[i] > maxN) maxN = Ns[i];
    }
    precompute_fact(maxN); 

    for (int i = 0; i < T; ++i) {
        cout << count_for_N(Ns[i]) << nline;
    }

    return 0;
}
