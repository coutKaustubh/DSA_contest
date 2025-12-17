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
    ll n, m;
        cin >>n >> m;

        iv(a,n);
        iv(b,n);

        vector<ll> pref(n+1,0);
        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + b[i];

        ll totalB = pref[n];

        ll C = LLONG_MIN;
        for (int i = 0; i < n; i++) {
            ll suffix = totalB - pref[i + 1];
            C = max(C, a[i] + suffix);
        }

        ll X0 = C - totalB;

        ll k = min(m, max(0LL, X0));
        ll ans = 0;
             ans += k * C;

        
        if (k < m) {
            ll cnt = m - k;
            ll sumX = (k + 1 + m) * cnt / 2;
            ans += sumX + cnt * totalB;
        }

        cout << ans << '\n';
   
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
        
  