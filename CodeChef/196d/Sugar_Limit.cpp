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
    ll n;
    cin >> n;
    iv(a, n); 
    iv(b, n); 

    vector<pair<ll, ll>> snacks(n);
    for (ll i = 0; i < n; i++) {
        snacks[i] = {b[i], a[i]}; 
    }

    sort(snacks.begin(), snacks.end()); 

    multiset<ll> tastiness;
    ll sumTasty = 0, maxSatisfaction = LLONG_MIN;

    for (ll i = 0; i < n; i++) {
        if (snacks[i].second > 0) {
            tastiness.insert(snacks[i].second);
            sumTasty += snacks[i].second;
        }
        ll L = snacks[i].first;
        maxSatisfaction = max(maxSatisfaction, sumTasty - L);
    }

    cout << max(0LL, maxSatisfaction) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}