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

void solve(){
    ll n, x, y;
    cin >> n >> x >>y;
    iv(p, n);
    if(x==0) {
        auto it = min_element(p.begin(), p.begin() + y);
        int idx = it - p.begin(); 
        for(int i=idx;i<y;i++) cout<<p[i]<<" ";
        for(int i=0;i<idx;i++) cout<<p[i]<<" ";
        for(int i=y;i<n;i++) cout<<p[i]<<" ";
        cout<<"\n";
        return;
    }
    else if(y==n){
        auto it = max_element(p.begin() + x, p.end());
        int idx = it - p.begin(); 
        for(int i=idx;i<n;i++) cout<<p[i]<<" ";
        for(int i =x;i<idx;i++) cout<<p[i]<<" ";
        for(int i=0;i<x;i++) cout<<p[i]<<" ";
        cout<<"\n";
        return;
    }
    
    
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