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

    
#define MOD (998244353)
#define INF 1000000000000000000LL 
#define mp make_pair
#define nline '\n'
#define yes cout << "Yes\n"
#define no cout << "No\n"

ll modPw(ll a, ll e){
    a %= MOD;
    ll r = 1;
    while(e){
        if(e & 1) r = (r * a) % MOD;
        a = (a * a) % MOD;
        e >>= 1;
    }
    return r;
}
void solve(){

         ll N, K;
        cin >> N >> K;
        
        if(K == 0){
            cout << 0 << '\n';
        }

        ll s = 0;
        ll perm = 1; 
        ll upto = min(N, K);
        
        
        ll gN = 0;
        for(ll d = 1; d <= upto; ++d){
            
            perm = (perm*((K-d+1)%MOD))%MOD;
            ll base = K-d+1;
            ll exp = N-d;
            ll pTerm =1;
            if(exp >0){
                pTerm = modPw((base % MOD + MOD) % MOD, exp);
            }
            ll gd = (perm * pTerm) % MOD;
            if(d <= N-1) {
                s += gd;
                if(s >= MOD) s -= MOD;
            }
            if(d == N) gN = gd;
        }
        ll ans = (s - ((ll)(N-1) % MOD) * (gN % MOD)) % MOD;
        if(ans < 0) ans += MOD;
        cout << ans << '\n';


}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}