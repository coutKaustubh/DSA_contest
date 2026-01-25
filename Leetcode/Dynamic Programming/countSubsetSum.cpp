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
    ll n;
    cin>>n;
    ll s;
    cin>>s;
    iv(a,n);
    vector<vector<ll>> dp(n + 1, vector<ll>(s + 1, 0));
    for(int i=0;i<n+1;i++){
        dp[i][0] = 1;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=s;j++){
            if(a[i-1] <= j){
                dp[i][j] = dp[i-1][j-a[i-1]]+dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
  
    cout<<dp[n][s]<<endl;
    
   
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}