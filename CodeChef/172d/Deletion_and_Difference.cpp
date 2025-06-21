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

#define create_vector vector<ll>v(n)
#define ump unordered_map
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
    create_vector;
    ump<int,int>u;
        f(i,n){
        cin>>v[i];
        u[v[i]]++;
    }
    ll ceven=0,codd=0,czero=0,cone=0;
    for(auto &val : u){
        if(val.first == 0){
            czero=1;
        }
        else if(val.second % 2 == 0){
            ceven++;
        }
        else if(val.second != 1 && val.second %2 !=0) {
            codd++;
        }
        else if(val.second == 1)cone++;
    }
    if(czero == 1){
        if(codd>0 && ceven>0) cout<<codd+cone<<endl;
        else if(codd == 0 && ceven >0) cout<<1+cone<<endl;
        else if(codd==0 && ceven == 0) cout<<cone<<endl;
    }
    else{
        if(codd>0 && ceven>0) cout<<codd+cone<<endl;
        else if(codd == 0 && ceven >0) cout<<1+cone<<endl;
        else if(codd==0 && ceven == 0) cout<<cone<<endl;
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