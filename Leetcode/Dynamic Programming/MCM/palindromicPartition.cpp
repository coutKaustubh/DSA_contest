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
bool isPal(const string &s, int l, int r) {
    while(l < r){
        if(s[l] != s[r]) return false;
        l++;
        r--;
    }
    return true;
}
vector<vector<int>>dp;
int palindromePartitioning(string s,int i,int j){
    if(i>=j)return 0;
    if(isPal(s,i,j))return 0;
    if(dp[i][j] != -1)return dp[i][j];
    int mn = INT_MAX;
    for(int k=i;k<j;k++){
        // int tmp = 1+palindromePartitioning(s,i,k)+palindromePartitioning(s,k+1,j);

        // one more optimisation bcz may be here ki palindromePartitioning(s,i,k) ye wala part ho chuka jho slve but dusra wala nhi so hmlog wapas pehla + dusra kr rhe 
        // usse bdhiya lets check ki agar dono me se ek bhi pehel call ho chuki hg to return directly like belowww

        int left,right;
        if(dp[i][k] != -1){
            left = dp[i][k];
        }
        else left = palindromePartitioning(s,i,k);
        if(dp[k+1][j] != -1){
            right = dp[k+1][j];
        }
        else right = palindromePartitioning(s,k+1,j);

        int tmp = 1 + left+right;

        mn = min(mn,tmp);
    }
    return dp[i][j] = mn;
}
void solve(){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    dp.assign(n+1 , vector<int>(n+1,-1));
    cout<<palindromePartitioning(s,0,n-1)<<nline;
   
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