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
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    ll baseSum = 0;
    f(i, N) {
        cin >> A[i];
        baseSum += A[i];
    }

    sort(A.begin(), A.end());

    ll ans = baseSum;  

    
    vector<ll> subs;
    subs.push_back(0);
    for (ll x : A) {
        if (x > 0) subs.push_back(M - x);
    }

    for (ll k : subs) {
        
        ll idx = lower_bound(A.begin(), A.end(), M - k) - A.begin();
        ll cnt = N - idx;
        ll sumK = baseSum + N * k - M * cnt;
        ans = min(ans, sumK);
    }

    cout << ans << nline;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
