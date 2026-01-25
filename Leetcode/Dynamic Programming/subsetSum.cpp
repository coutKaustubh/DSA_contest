// RECURSIVE + MEMOIZATION

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define f(i, n) for (ll i = 0; i < n; i++)
#define ia(a, n) \
    ll a[n];     \
    f(i, n) cin >> a[i]
#define iv(v, n)     \
    vector<ll> v(n); \
    f(i, n) cin >> v[i]

#define create_matrix(mat, n, m) vector<vector<ll>> mat(n, vector<ll>(m));
#define input_matrix(mat, n, m) f(i, n) f(j, m) cin >> mat[i][j];

#define MOD (1000000007)
#define INF 1000000000000000000LL // Infinity for ll
#define mp make_pair
#define nline '\n'
#define yes cout << "Yes\n"
#define no cout << "No\n"

vector<vector<int>> dp;

bool subsetSum(vector<ll> &a, ll n, ll s)
{
    if (s == 0)
        return true;
    if (n == 0)
        return false;

    if (dp[n][s] != -1)
        return dp[n][s];

    if (a[n - 1] <= s)
    {
        dp[n][s] = subsetSum(a, n - 1, s - a[n - 1]) || subsetSum(a, n - 1, s);
    }
    else
    {
        dp[n][s] = subsetSum(a, n - 1, s);
    }

    return dp[n][s];
}

void solve()
{
    ll n, s;
    cin >> n >> s;

    iv(a, n);

    dp.assign(n + 1, vector<int>(s + 1, -1));

    if (subsetSum(a, n, s))
        yes;
    else
        no;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

   solve();

    return 0;
}



// OR TOP DOWN APPROACH


// #include <bits/stdc++.h>

// using namespace std;

// #define ll long long
// #define f(i, n) for (ll i = 0; i < n; i++)
// #define ia(a, n) \
//     ll a[n];     \
//     f(i, n) cin >> a[i]
// #define iv(v, n)     \
//     vector<ll> v(n); \
//     f(i, n) cin >> v[i]

// #define create_matrix(mat, n, m) vector<vector<ll>> mat(n, vector<ll>(m));
// #define input_matrix(mat, n, m) f(i, n) f(j, m) cin >> mat[i][j];

// #define MOD (1000000007)
// #define INF 1000000000000000000LL // Infinity for ll
// #define mp make_pair
// #define nline '\n'
// #define yes cout << "Yes\n"
// #define no cout << "No\n"


// void solve()
// {
//     ll n,s;
//     cin >> n>>s;
//     iv(a, n);
//     vector<vector<bool>> dp(n + 1, vector<bool>(s + 1, false));

//     for(int i=0;i<n+1;i++){
//         dp[i][0] = true;
//     }

//     for(int i=1;i<n+1;i++){
//         for(int j=1;j<s+1;j++){
//             if(a[i-1] <= j){
//                 dp[i][j] = dp[i-1][j-a[i-1]] || dp[i-1][j];
//             }
//             else dp[i][j] = dp[i-1][j];
//         }
//     }

    
//     if (dp[n][s])
//         yes;
//     else
//         no;
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//         solve();
    

//     return 0;
// }