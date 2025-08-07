#include<bits/stdc++.h>
using namespace std;

//Typedef
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;

//MACROS
#define rep(i, a, b) for (ll i = a; i < b; ++i)
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define ff first
#define ss second
#define yes cout << "YES\n"
#define no cout << "NO\n"

void solve()
{
    ll n;
    cin>>n;
    
    vll a(n);
    rep(i,0,n) a[i]=i+1;
    
    cout<<2<<endl;
    rep(i,0,n) cout<<a[i]<<" ";
    cout<<endl;
    for(int i=n-1;i>=0;i--) cout<<a[i]<<" ";
    cout<<endl;
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    while(t--)
    {
       solve();
    }
}