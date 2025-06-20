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
#define MOD (1000000007)
#define INF 1000000000000000000LL // Infinity for ll
#define mp make_pair
#define nline '\n'
#define yes cout << "Yes\n"
#define no cout << "No\n"

void solve(){
    ll n,M;
    cin>>n>>M;
    iv(x,n);
    iv(r,n);
    unordered_map<ll,ll>m;
    
    f(i,n){
        ll start = x[i] - r[i];
        ll end = x[i] + r[i];
        for(ll xi = start;xi<=end;xi++){
            ll y = (sqrt(r[i]*r[i] - (xi-x[i])*(xi-x[i]) ));
            m[xi] = max(m[xi], 2*y+1);
        }
    }
    ll count  = 0;
    for (auto&x : m){
        count+=x.second;
    }
    cout<<count<<endl;



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