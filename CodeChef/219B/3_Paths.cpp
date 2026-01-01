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
#define INF 1000000000000000000LL 
#define mp make_pair
#define nline '\n'
#define yes cout << "Yes\n"
#define no cout << "No\n"

void solve(){
    ll n;
        cin >> n;

        if (n == 2) {
            cout << -1 << '\n';
            return ;
        }

        
        vector<vector<ll>> a(51, vector<ll>(51, 0)); 

        
        a[1][1] = 1; a[1][2] = 1; a[1][3]=1;
        a[2][1] = 1; a[2][2] = 1; a[2][3]=1;

        
        for (ll j = 0; j < n; j++) {
            a[j][j] = 1;
        }

        
        for (ll i = 1; i < n; i++) {
            a[i-1][i] = 1;
        }

        if(n==3){
            a[0][2]=1;
        }
        
        f(i,n) {
            for (ll j = 0; j < n; j++) {
                if (j) cout << " ";
                cout << a[i][j];
            }
            cout << '\n';
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