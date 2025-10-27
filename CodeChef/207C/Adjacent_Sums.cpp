#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, n) for (ll i = 0; i < n; i++)
#define ia(a, n) \
    ll a[n];     \
    f(i, n) cin >> a[i]
#define iv(v, n)     \
    vector<ll> v(n); \
    f(i, n) cin >> v[i]
#define create_matrix(mat, n, m) vector<vector<ll>> mat(n, vector<ll>(m));
#define input_matrix(mat, n, m) f(i, n) f(j, m) cin >> mat[i][j];
#define MOD (1000000007)
#define INF 1000000000000000000LL
#define mp make_pair
#define nline '\n'
#define yes cout << "Yes\n"
#define no cout << "No\n"
const ll A = 4e18;

void solve()
{
    ll n;
    cin >> n;
    iv(a, n);

    vector<vector<ll>> E(n, vector<ll>(2, A));
    E[0][0] = a[0];
    E[0][1] = A;
    E[1][0] = a[0] + a[1];
    E[1][1] = abs(a[0] - a[1]);
    for (ll F = 2; F < n; F++)
    {
        E[F][0]=min(E[F - 1][0], E[F - 1][1]) + a[F];
        E[F][1]=E[F - 2][0] + abs(a[F - 1] - a[F]);
    }
    cout << min(E[n - 1][0], E[n - 1][1]) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
