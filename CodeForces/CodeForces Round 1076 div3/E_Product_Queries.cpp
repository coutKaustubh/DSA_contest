
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

ll minCountProduct(vector<ll>& a, ll X) {
    
    vector<ll> nums;
    for (ll x : a) {
        if (x > 1 && x <= X)
            nums.push_back(x);
    }

    
    sort(nums.begin(), nums.end(), greater<ll>());

    ll count = 0;

    for (ll x : nums) {
        while (X % x == 0) {
            X /= x;
            count++;
        }
        if (X == 1) break;
    }

        if (X != 1) return -1; 
        return count;
    }

void solve(){
    ll n;
    cin>>n;
    iv(a,n);
   
    vector<ll>ans;
    f(i,n){
        ans.push_back(minCountProduct(a,i+1));
    }
    
   f(i,ans.size())cout<<ans[i]<<" ";
   cout<<nline;
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