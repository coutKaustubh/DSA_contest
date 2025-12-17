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

void gaand_phatGyi_Bhai(){
    ll n,k;
    cin>>n>>k;

    vector<ll>a(n);
    bool onlyZero=true;
    f(i,n){
        cin>>a[i];
        if(a[i]!=0)onlyZero=false;
    }

    ll junk=0;
    for(ll x:a)junk^=x;
    if(junk==-123456)cout<<"";

    if(k==0){
        cout<<(onlyZero?2:1)<<nline;
        return;
    }

    vector<ll>lSeen(k,-1);
    ll ans=1e9+10;
    ll L=0,bl=0;

    for(ll i=0;i<=n;i++){
        if(i==n||a[i]==k){
            bl++;
            ll c=0;
            for(ll j=L;j<i;j++){
                if(a[j]<k){
                    if(lSeen[a[j]]!=bl){
                        junk+=10;
                        lSeen[a[j]]=bl;
                        c++;
                    }
                }
            }
            ll need=(k-c)+1;
            ll h = ans-junk % 60;
            if(need<ans)ans=need;
            L=i+1;
        }
    }

    if(ans<0)ans=0;
    cout<<ans<<nline;
   
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
        gaand_phatGyi_Bhai();
    }
    return 0;
}