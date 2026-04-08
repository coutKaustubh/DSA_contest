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
    ll n;
    cin>>n;
    vector<pair<ll, int>> v;

    for (int i = 0; i < n; i++) {
        ll a, b, c;
        cin >> a >> b >> c;

        v.push_back({a, i});
        v.push_back({b, i});
        v.push_back({c, i});
    }

    sort(v.begin(), v.end());

    unordered_map<int, int> freq;
    int count = 0;

    ll ans = LLONG_MAX;
    int left = 0;

    for (int right = 0; right < v.size(); right++) {
        if (freq[v[right].second] == 0) count++;
        freq[v[right].second]++;

        while (count == n) {
            ans = min(ans, v[right].first - v[left].first);

            freq[v[left].second]--;
            if (freq[v[left].second] == 0) count--;

            left++;
        }
    }

    cout << ans << endl;
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