#include <bits/stdc++.h>



using namespace std;


#define ll long long
#define f(i,n) for (ll i = 1; i <= n; i++)
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
    ll m;cin>>m;
    string s1,s2;
    cin>>s1>>s2;
    vector<vector<ll>>dp(n+1, vector<ll>(m+1,0));
    
    f(i,n){
        f(j,m){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
        }
    }
    int i=n,j=m;
    string ans;
            while(i!=0 && j!=0){
                if(s1[i-1] == s2[j-1]){
                    ans.push_back(s1[i-1]);
                    i--;
                    j--;
                }
                else{
                    if(dp[i-1][j] > dp[i][j-1])i--;
                    else  j--;
                }
            }
            reverse(ans.begin(),ans.end());
            cout<<ans<<endl;
        }
   



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}