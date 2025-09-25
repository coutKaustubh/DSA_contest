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
const ll NEG = (ll)-9e18;
void solve(){
 ll n, K;
    cin >> n >> K;
    vector<ll> W(n), C(n);
    for (ll i = 0; i < n; ++i) cin >> W[i];
    for (ll i = 0; i < n; ++i) cin >> C[i];

    unordered_map<ll,ll> stored;
    stored.reserve(n * 2);
    ll add = 0;
    ll floor_val = NEG;      
    stored[0] = 0;           
    ll max_stored = 0;       

    
    for (ll i = 1; i < n; ++i) {
        ll x = C[i];
        ll w = W[i];
        
        ll maxS = max_stored;         
        ll base = maxS - K;           

        ll old_x = floor_val;
        auto it = stored.find(x);
        if (it != stored.end()) old_x = it->second;
      
        if (base > floor_val) floor_val = base;

        ll new_x = 2 * w + max(old_x, base);
        stored[x] = new_x;

        
        add -= w;

        
        if (new_x > max_stored) max_stored = new_x;
        if (floor_val > max_stored) max_stored = floor_val;
    }

    ll answer = add + max_stored;
    cout << answer << '\n';
   
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