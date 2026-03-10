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

vector<vector<int>>dp;
int mcm(vector<ll>&a,ll l,ll r){
    ll minA = INT_MAX;
    if(l>=r)return 0;
    if(dp[l][r] != -1)return dp[l][r];
    for(int k = l;k<=r-1;k++){
        ll temp = mcm(a,l,k)+mcm(a,k+1,r) + a[l-1]*a[k]*a[r];
        minA = min(minA,temp);
    }
    return dp[l][r] = minA;
}
void solve(){
    ll n;
    cin>>n;
    iv(a,n);
    dp.assign(n+1,vector<int>(n+1,-1));
    cout<<mcm(a,1,n-1)<<nline;;
   
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