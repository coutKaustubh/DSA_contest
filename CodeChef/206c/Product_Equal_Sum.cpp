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
    ll n;
    cin >> n;
    vector<ll> A(n);
    f(i,n) cin >> A[i];

    ll good = n; 

    for (int i = 0; i < n; i++) {
        
        if (i + 1 < n) {
            if (A[i] + A[i+1] == A[i] * A[i+1])
                good++;
        }
        if (i + 2 < n) {
            ll sum = A[i] + A[i+1] + A[i+2];
            ll prod = A[i] * A[i+1] * A[i+2];
            if (sum == prod) good++;
        }
        
        if (i + 3 < n) {
            ll sum = A[i] + A[i+1] + A[i+2] + A[i+3];
            ll prod = A[i] * A[i+1] * A[i+2] * A[i+3];
            if (sum == prod) good++;
        }
    }

    cout << good << nline;
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
