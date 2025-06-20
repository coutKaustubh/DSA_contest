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

vector<ll>fib = {1,2,3,5,8,13,21,34,55,89};

void solve(){
    ll n,m;
    cin>>n>>m;
    create_matrix(mat,m,3);
    input_matrix(mat,m,3);
    ll req = fib[n-1];
    ll req2 = fib[n-1] + fib[n-2];
    ll cSame=0;
    ll cdiff=0;
    f(i,m){
        f(j,3){
            if(mat[i][j] >= req2)cdiff++;
            if(mat[i][j]>= req)cSame++;
        }
        if(cSame >= 3 && cdiff >= 1)cout<<1;
        else cout<<0;
        cSame=0;
        cdiff=0;
    }
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