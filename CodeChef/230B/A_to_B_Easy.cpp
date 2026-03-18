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
    
    ll n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    if (a == b) { cout << 0 << nline; return; }

    auto allSame = [](const string& s) {
        return s == string(s.size(), s[0]);
    };

    bool aAllSame = allSame(a);
    bool bAllSame = allSame(b);

    if (!aAllSame && !bAllSame) {
        cout << 0 << nline;
    } else {
        cout << 1 << nline;
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