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
vector<vector<ll>>dp;
int LCS(string &s1 , string &s2, int n,int m){
    if(n==0 || m==0)return 0;
    if(dp[n][m] != -1)return dp[n][m];
    if(s1[n-1] == s2[m-1]){
        return dp[n][m] = 1 + LCS(s1,s2,n-1,m-1);
    }
    else return dp[n][m] = 0;
    
    
}
void solve(){
    ll n,m;
    cin>>n>>m;
    
    string s1,s2;
    cin>>s1>>s2;
    ll c=0;
    dp.assign(n+1,vector<ll>(m+1,-1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            c = max(c,(ll)LCS(s1,s2,i,j));
        }
    }
    cout<<c<<endl;

    
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