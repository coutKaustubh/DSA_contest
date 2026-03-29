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
ll lcm(ll a, ll b){
    if(a==0 || b==0) return 0;
    return (a/__gcd(a,b)) * b;
}
void solve(){
    ll n;
    cin>>n;
    iv(a,n);
    iv(b,n);
    if(n==1){
        cout<<1<<nline;
        return;
    }
    ll ans = 0;

    f(i,n){
        ll m;
        if(i==0){
            m =__gcd(a[0], a[1]);
        }
        else if(i==n-1){
            m = __gcd(a[n-2], a[n-1]);
        }
        else{
            ll L = __gcd(a[i-1], a[i]);
            ll R = __gcd(a[i], a[i+1]);
            m = lcm(L, R);
        }
      
        if(m < a[i]) ans++;
    }

    cout << ans << endl;
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