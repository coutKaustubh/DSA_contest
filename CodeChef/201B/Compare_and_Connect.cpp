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
    long long n, m;
        cin >> n >> m;

        
        string res;
        if (n + m > 0) res.reserve((size_t)max(1LL, 2*(n+m)-1));

        if (n == 0) {
            if (m == 1) {
                res = ">";
            } else { 
                res.push_back('>');
                for (long long i = 0; i < m - 2; ++i) {
                    res.push_back('<');
                    res.push_back('>');
                }
                res.push_back('=');
                res.push_back('>');
            }
        } else if (m == 0) {
            if (n == 1) {
                res = "<";
            } else { 
                res.append((size_t)(2*n - 3), '<');
                res.push_back('=');
                res.push_back('<');
            }
        } else {
            
            res.append((size_t)(2*n), '<');
            for (long long i = 1; i <= m; ++i) {
                res.push_back('>');
                if (i < m) res.push_back('<');
            }
        }

        cout << res << '\n';

   
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