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

// Problem: Given an array, divide it into two subsets such that the difference of their sums is minimized.

// Logic:
// 1. Array ka total sum S hota hai. Subset sums 0 se lekar S tak vary kar sakte hain.
// 2. Hum ek DP array (boolean) banayenge jo batayega ki kaun-kaaunse sums possible hain.
// DP[i] true hoga agar i sum kisi subset se ban sakta hai.
// 3. Subset sum DP solve karenge, jo standard problem hai: 
// 4. Jab DP matrix ban jayega, toh hum dekhenge ki kaunse sums possible hain,jahan jahan true hoga vo posible store it in newRange array
//(becaiuse old ranger was 0 to arr(sum) )
// fir us array newRange koi uniqyue krenge and then sort and then middle element - aur ausse phel wala elemnt

// Example: Array = {1, 2, 7}
// Total sum S = 10
// Possible subset sums (from DP) = {0, 1, 2, 3, 7, 8, 9, 10}
// Difference = 7 - 3 = 4


void solve(){
    ll n;
    cin>>n;
    iv(a,n);
    ll MaxSum = accumulate(a.begin(),a.end(),0);

    vector<vector<bool>>dp(n+1,vector<bool>(MaxSum+1 , false));

    for(int i=0;i<=n;i++){
        dp[i][0] = true;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=MaxSum;j++){
            if(a[i-1] <= j){
                dp[i][j] = dp[i-1][j-a[i-1]] || dp[i-1][j];
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    vector<ll>newRange;

    for(int i=0;i<=n;i++){
        for(int j=0;j<=MaxSum;j++){
            if(dp[i][j])newRange.push_back(j);
        }
    }
    sort(newRange.begin(), newRange.end());
    newRange.erase(unique(newRange.begin(), newRange.end()), newRange.end());

   

    cout<<abs(newRange[newRange.size()/2] - newRange[newRange.size()/2 - 1]);
   
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}