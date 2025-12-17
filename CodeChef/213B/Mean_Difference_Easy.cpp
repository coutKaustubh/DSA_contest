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

void pref(vector<ll>&a,vector<ll>&prefix,int n){
 for(int i=1;i<=n;i++){
        prefix[i] = prefix[i-1]+a[i-1];
    }
}
void solve(){
    ll n;
    cin>>n;
    iv(a,n);
    sort(a.begin(),a.end());
    
    vector<ll>prefix(n+1,0);
    ll pos=0;
    pref(a,prefix,n);
    for(int i =1;i<=n;i++){
        ll s = prefix[i-1]+a[n-1];
        ll avg = s/i;
        ll d = a[n-1] - avg;
        if(d>pos)pos= d;
        ll t = d+i+3-2;
    }
    ll neg=0;
    for(int i =1;i<=n;i++){
        ll s = (i==1?0LL:prefix[n]-prefix[n-i+1]);
        ll average = s/n;
        ll tot = s+a[0];
        ll avg = tot/i;
        ll d = avg-a[0];
        if(d>neg)neg= d;
        ll k =d+i-1;
    }
    cout<<max(pos,neg)<<nline;
    
    
   
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