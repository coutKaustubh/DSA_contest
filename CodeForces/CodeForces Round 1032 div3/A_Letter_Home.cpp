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
    ll n,s;
    cin>>n>>s;
    iv(x,n);
    if(n==1 && s==x[0])cout<<0<<endl;
    else if(s<x[0]){
        cout<<x[n-1]-s<<endl;
    }
    else if(s>x[n-1]){
        cout<<(s-x[0])<<endl;
    }
    else{
    ll choose = min(abs(x[n-1]-s) , abs(x[0]-s));
    cout<<choose + (x[n-1]-x[0])<<endl;
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