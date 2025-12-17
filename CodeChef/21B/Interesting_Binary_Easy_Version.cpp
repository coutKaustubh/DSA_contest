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
    vector<ll> a(n);
    for (auto &x : a) cin >> x;

    map<int, ll> prevC;
    for (int i = 0; i <= 2; i++)
        prevC[i] = i;

    for (int idx = 1; idx < n; idx++) {
        map<int, ll> curr;
        for (int i = 0; i <= 2; i++) curr[i] = INF;

        for (int i = 0; i <= 2; i++) {
            ll newVal = a[idx] + i;
            for (int j = 0; j <= 2; j++) {
                ll prevVal = a[idx - 1] + j;
                if (prevVal != newVal)
                    curr[i] = min(curr[i],prevC[j] + i);
            }
        }
        prevC = curr;
    }

    ll res = INF;
    for (auto &[k, v] : prevC) res = min(res, v);
    cout << res << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();
}
