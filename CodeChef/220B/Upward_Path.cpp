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
#define inf 1000000000000000000LL 
#define mp make_pair
#define nline '\n'
#define yes cout << "Yes\n"
#define no cout << "No\n"

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;

    vector<int> lo(n), hi(n);
    for (int i = 0; i < n; i++) {
        lo[i] = min(a[i], b[i]);
        hi[i] = max(a[i], b[i]);
    }

    const int INF = 1e9;
    vector<int> L(n + 1, INF), R(n + 2, INF);
    L[0] = 0;

    for (int i = 1; i <= n; i++)
        L[i] = hi[i - 1] < L[i - 1] ? INF :(lo[i - 1] >= L[i - 1] ? lo[i - 1] : hi[i - 1]);

    for (int i = n; i >= 1; i--)
        R[i] = hi[i - 1] <= R[i + 1] ? hi[i - 1] :(lo[i - 1] <= R[i + 1] ? lo[i - 1] : -1);

    for (int i = 1; i <= n; i++)
        if (L[i - 1] <= lo[i - 1] && hi[i - 1] <= R[i + 1]) {
            yes;
            return;
        }

    no;
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