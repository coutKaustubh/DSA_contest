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

bool ok(string s, string t){
    int n = s.size();

    for(int i = 0; i < n; i++){
        if(s.compare(0, i+1, t, n-(i+1), i+1) == 0){
            
            if(s.compare(i+1, n-(i+1), t, 0, n-(i+1)) == 0){
                return true;
            }
        }
    }
    return false;
}
void solve(){
    ll n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    bool ok = false;

if(ok) cout << "YES\n";
else cout << "NO\n";
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