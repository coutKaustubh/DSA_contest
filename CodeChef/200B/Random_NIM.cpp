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

#define yes cout << "Yes\n"
#define no cout << "No\n"

const ll MOD_GAME = 998244353;

void solve(){
    ll n;
    cin >> n;
    bool all_one = true;
    f(i,n){
        ll x; cin >> x;
        if(x != 1) all_one = false;
    }

    if(all_one){
        if(n % 2 == 1) cout << 1 << endl;
        else cout << 0 << endl;
    } else {
        cout << (MOD_GAME + 1) / 2 << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
