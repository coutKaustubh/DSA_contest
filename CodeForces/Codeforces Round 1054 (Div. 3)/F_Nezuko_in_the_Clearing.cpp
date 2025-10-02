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

void solve(){
    ll h, d;
        cin >> h >> d;

        
        ll k = (ll)(floor((-1.0 + sqrt(1.0 + 8.0 * h)) / 2.0));

        ll ans;
        if (k >= d) {
            ans = d+1;
        } else {
            
            ll remaining = d - k;
            ans = k + 2 * remaining;
        }

        
        cout << ans << "\n";
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