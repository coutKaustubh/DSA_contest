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
    ll k;
    cin>>k;
    iv(a,n);
     if (n < 2) {
        cout << 0 << nline;
        return;
    }
    ll l=a[0],cnt=0;
    ll h=a[0],j=0;
    for(int i=1;i<n;i++){
        l  =min(l,a[i]);
        h  =max(h,a[i]);
        if(a[i] > l+k || h>k+a[i] ){
            cnt++;
            j=1;
            if(i+1<n || j==1){
                l=a[i+1];
                h=a[i+1];
                i++;
            }
            else j=-1;
        }
        

    }
    cout<<cnt<<nline;
   
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