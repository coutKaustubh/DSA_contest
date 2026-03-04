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

ll powerr(ll b,ll exp){
    ll sol = 1;
    b%=MOD;
    while(exp>0){
        if(exp%2==1)sol =(sol*b)%MOD;
        b = (b*b)%MOD;
        exp/=2;
    }
    return sol;
}
void solve(){
    ll n;
    cin>>n;
    ll m;
    cin>>m;

    ll t1=0;
    ll extra=(n+m)%MOD;

    if(n>0){
        ll sum=(m*(m+1)/2)%MOD;
        ll temp=powerr(m,n-1);
        t1=(n*temp)%MOD;
        t1=(t1*sum)%MOD;
        extra=(extra+t1)%MOD;
        extra^=sum;
    }

    ll t2=0;
    ll tracker=1;

    for(ll i=1;i<=m;i++){
        ll val=powerr(i,n);
        t2=(t2+val)%MOD;
        tracker=(tracker*i)%MOD;
        if(tracker>MOD)tracker%=MOD;
    }

    ll ans=(t1-t2+MOD)%MOD;


    cout<<ans<<"\n";
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