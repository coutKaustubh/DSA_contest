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

#define MOD (1000000007)
#define INF 1000000000000000000LL
#define mp make_pair
#define nline '\n'
#define yes cout << "Yes\n"
#define no cout << "No\n"


 ll T_cost(ll s) {
    if (s<=1)return 0;
    
    if ((s & (s - 1))== 0) {
        ll k = 0, t = s;
        while (t > 1){ 
            t >>= 1; 
            ++k;
         }        
        return k*(s >> 1);
    }
    
    ll p = 1LL << (63 - __builtin_clzll(s - 1));
    return T_cost(p) + T_cost(s - p) + p;
}


 ll F_cost(ll N) {
    if (N <= 1) return 0;
    ll m = 1LL << (63 - __builtin_clzll(N));   
    ll s = N - m + 1;                          

    ll left  = F_cost(m - 1);                  
    ll upper = T_cost(s);                      
    ll cross = m + (s == 1 ? 1 : 0);           

    return left + upper + cross;
}

void solve(){
    ll n; 
    cin >> n;
    cout << F_cost(n) << nline;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}
