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
    ll n; cin >> n;
    iv(a,n);
    iv(c,n);

    vector<ll> dp(n);
    ll total = accumulate(c.begin(), c.end(), 0LL);

    ll ans = 0;
    for(int i=0; i<n; i++){
        dp[i] = c[i];
        for(int j=0; j<i; j++){
            if(a[j] <= a[i])
                dp[i] = max(dp[i], dp[j] + c[i]);
        }
        ans = max(ans, dp[i]);
    }

    cout << total - ans << "\n";
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