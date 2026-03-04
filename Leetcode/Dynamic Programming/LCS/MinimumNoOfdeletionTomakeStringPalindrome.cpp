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

int LCS(string &s1,string &s2, int n){
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1+ dp[i-1][j-1];
                }
                else dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);

            }

        }
            return dp[n][n];
}
#define MOD (1000000007)
#define INF 1000000000000000000LL // Infinity for ll
#define mp make_pair
#define nline '\n'
#define yes cout << "Yes\n"
#define no cout << "No\n"

void solve(){
    ll n;
    cin>>n;
    string s2;
    cin>>s2;
    string s1 = s2;
    reverse(s2.begin(),s2.end());
    // now we have s1 and s2 , so LCS of s1 and S2 will give longest palindromic subsequence, so if len = 4 of palindrome so required asnwer here is n-len
    cout<< n- LCS(s1,s2,n)<<endl;

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