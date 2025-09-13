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
 
void solve(){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    bool flag=false;
    ll c=0;
    f(i,n-2){
        if(s[i] == s[i+1] && s[i] == s[i+2] && s[i] == '.'){
            flag=true; 
            break;
        }  
        
    }
    f(i,n){
        if(s[i] == '.')c++;
    }
    if(flag)cout<<2<<endl;
    else cout<<c<<endl;
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