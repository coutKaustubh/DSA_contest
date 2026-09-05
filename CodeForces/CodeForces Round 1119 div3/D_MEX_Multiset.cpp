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
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;

    ll cnt0 = count(a.begin(), a.end(), 0);

    if (cnt0 == 1) {
        cout << "NO\n";
        return;
    }

    string s(n, 'C');
    bool firstZero = true;
    for (ll i = 0; i < n; i++) {
        if (a[i] == 0) {
            if (firstZero) { s[i] = 'A'; firstZero = false; }
            else s[i] = 'B';
        }
    }
    fill(s.begin(), s.end(), 'C');
    int zerosSeen = 0;
    for (ll i = 0; i < n; i++) {
        if (a[i] == 0) {
            zerosSeen++;
            if (zerosSeen == 1) s[i] = 'A';
            else if (zerosSeen == 2) s[i] = 'B';
            else s[i] = 'A'; 
        }
    }

    cout << "YES\n" << s << "\n";
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