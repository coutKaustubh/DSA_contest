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
#define NEG -9e18


void solve(){
        ll n;
        cin >> n;
        iv(a,n);

       
        vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, NEG));

        dp[0][0] = 0; 

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (dp[i - 1][j] == NEG) continue;

                int cur = j + 1;              
                int maxsell = min(2, cur);           

                for (int k = 0; k <= maxsell; k++) {
                    int inv_new = cur - k;
                    ll profit = dp[i - 1][j]
                              + (ll)k * a[i - 1];

                    dp[i][inv_new] = max(dp[i][inv_new], profit);
                }
            }
        }

        ll ans = 0;
        for (int i = 0; i <= n; i++) {
            ans = max(ans, dp[n][i]);
        }

        cout << ans << '\n';
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
