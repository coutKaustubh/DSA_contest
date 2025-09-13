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
     int N; string A;
        cin >> N >> A;

        ll ans = 0;
        int u = 1, v = 1;                        
        int cur = (A[0] == '1');                 
        ans += cur;

        while (u != N || v != N) {
            if (u == v) {
                if (v < N) {
                    cur += (A[v] == '1');        
                    ++v;
                }
            } else if (v == N) {
                cur -= (A[u-1] == '1');          
                ++u;
            } else if (u == N) {
                cur += (A[v] == '1');            
                ++v;
            } else {
                int dec = (A[u-1] == '1');       
                int inc = (A[v]=='1');       
                if (cur-dec<= cur + inc) {
                    cur-= dec;      
                    ++u;
                } else {
                    cur+= inc;
                     ++v;
                }
            }
            ans+=cur;                           
        }

        cout << ans << "\n";
    
   
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