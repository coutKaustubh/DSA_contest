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

int judgeQuery(int i,int j){
    cout<<"? "<<i<<" "<<j<<endl;
    int x;
    cin>>x;
    return x;
}
void solve(){
    ll n;
    cin>>n;
    for(int i=1;i<= 2*n-2 ; i+=2){
        int x = judgeQuery(i,i+1);
        if(x==1){
            cout<<"! "<<i<<endl;
            return;
        }
    }
    int x = judgeQuery(1,(2*n-1));
    int y = judgeQuery(2,(2*n-1));
    if(x==1){
        cout<<"! "<<1<<endl;
        return;
    }
    else if(y==1){
        cout<<"! "<<2<<endl;
        return;
    }
    else{
        cout<<"! "<<2*n<<endl;
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