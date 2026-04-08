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
    int n; cin >> n;
    string s; cin >> s;
    bool allAlt = true;
    for (int i = 0; i < n; i++)
        if (s[i] == s[(i+1)%n]) {
            allAlt = false;
            break; 
        }
    if (allAlt) { 
        cout << -1 << "\n"; 
        return; 
    }
    int maxRun = 1, curRun = 1;
    string t = s + s;
    for (int i = 1; i < 2*n; i++) {
        if (t[i] != t[i-1]) curRun++;
        else curRun = 1;
        if (i < 2*n-1) 
            maxRun = max(maxRun, min(curRun, n));
    }

    cout << (maxRun + 1) / 2 << "\n";
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