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
    ll n, k;
    cin >> n >> k;

    vector<ll> a(n);
    f(i, n) cin >> a[i];

    
   unordered_map<int,int>freq;
     for (auto x : a) freq[x]++;

    
    bool possible = true;
    for (ll v = 1; v <= n; v++) {
        if (freq[v] % k != 0) possible = false;
    }

    if (!possible) {
        cout << 0 << nline;
        return;
    }

    ll ans = 0;
   unordered_map<int,int>mp;
    ll r = 0;

    for (ll l = 0; l < n; l++) {
        
        while (r < n) {
            if(mp[a[r]] < freq[a[r]]/k){
            mp[a[r]]++;
            r++;
            }
            else break;
        }     
        ans += (r - l);
        mp[a[l]]--;
    }

    cout << ans << nline;
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
