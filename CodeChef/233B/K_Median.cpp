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

void solve() {
    ll n, k;
    cin >> n >> k;
    iv(a, n);
    sort(a.begin(), a.end());

    ll m = n - k;
    ll need = (m + 1) / 2;

    set<ll> s;

    f(i,n){
        ll x = a[i];

        ll le = upper_bound(a.begin(), a.end(), x) - a.begin();
        ll ge = a.end() - lower_bound(a.begin(), a.end(), x);

        if (le >= need && ge >= (m - need + 1)) {
        s.insert(x);
}
    }

    for (ll x : s) cout << x << " ";
    cout << endl;
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