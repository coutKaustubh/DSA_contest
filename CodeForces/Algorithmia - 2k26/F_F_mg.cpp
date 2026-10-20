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
#define INF 1000000000000000000LL // Infinity for ll
#define mp make_pair
#define nline '\n'
#define yes cout << "Yes\n"
#define no cout << "No\n"

void solve(){
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m));
    for(auto &r : a) for(auto &x : r) cin >> x;

    auto get = [&](ll i, ll j) -> ll {
        if(i < 0 || j < 0 || i >= n || j >= m) return 0LL;
        return a[i][j];
    };

    vector<vector<bool>> fixedCell(n, vector<bool>(m, false));
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            // if(a[i][j] == 0) continue;
            ll u = get(i-1,j), d = get(i+1,j), l = get(i,j-1), r = get(i,j+1);
            ll sum = u + d + l + r;
            ll mx = max({u, d, l, r});
            if(sum > a[i][j] || mx >= a[i][j]) fixedCell[i][j] = true;
        }
    }

    vector<vector<ll>> ans(n, vector<ll>(m, 0));
    for(ll j = 0; j < m; j++){
        ll floorPos = n - 1;
        for(ll i = n - 1; i >= 0; i--){
            // if(a[i][j] == 0) continue;
            if(fixedCell[i][j]){
                ans[i][j] = a[i][j];
                floorPos = i - 1;
            } else {
                ans[floorPos][j] = a[i][j];
                floorPos--;
            }
        }
    }

    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++) cout << ans[i][j] << " ";
        cout << "\n";
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}