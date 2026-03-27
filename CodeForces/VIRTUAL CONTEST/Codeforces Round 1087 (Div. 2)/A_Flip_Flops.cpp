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
    ll n,c,k;
    cin>>n>>c>>k;
    iv(a,n);
    sort(a.begin(),a.end());
    ll cnt=c;
    f(i,n){
        if(a[i]<=c){
            cnt+=a[i];
            if(k>0){
                ll inc = c-a[i];
                if(inc<=k) {
                    k = k-inc;
                    cnt+=inc;
                }
                else{
                    if(c - (k+a[i]) >= 0){
                        cnt+=k;
                        k=0;
                    }
                    else{
                        cnt+=(c-a[i]);  
                    }
                }
            }
        }
        c = cnt;
    }
   cout<<cnt<<"\n";
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