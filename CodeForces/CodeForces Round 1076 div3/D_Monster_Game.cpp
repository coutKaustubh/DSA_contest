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

void solve() {
    int n;
    cin >> n;

    iv(a,n);
    iv(b,n);

    
    sort(a.begin(), a.end(), greater<ll>());

    
    vector<ll> prefB(n);
    prefB[0] = b[0];
    for (int i = 1; i < n; i++) {
        prefB[i] = prefB[i - 1] + b[i];
    }

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        ll x = a[i];          
        ll usable = i + 1;    

        
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (prefB[i] <= usable) {
                k++;
            } else {
                break;
            }
        }


        ans = max(ans, x * k);
    }

    cout << ans << nline;
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