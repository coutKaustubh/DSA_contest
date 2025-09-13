#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f(i,n) for (ll i = 0; i < n; i++)
#define iv(v, n) vector<ll> v(n); f(i,n) cin >> v[i]

#define MOD (1000000007)
#define INF 1000000000000000000LL
#define nline '\n'

void solve(){
    ll n, q;
    cin >> n >> q;

    iv(vec, n);
    vector<ll> a(n);

    
    a[0] = vec[0];
    ll ans = max(vec[0], vec[1]);
    a[1] = ans;

    for (int i = 2; i < n; i++) {
        if ((i+1) % 2) ans = min(ans, vec[i]);  
        else ans = max(ans, vec[i]);            
        a[i] = ans;
    }

    cout << ans << " ";

    while (q--) {
        ll x, val;
        cin >> x >> val;
        x--;                
        vec[x] = val;

        ll temp = (x == 0 ? LLONG_MAX : a[x-1]);
        for (int i = x; i < n; i++) {
            if ((i+1) % 2) temp = min(temp, vec[i]);
            else temp = max(temp, vec[i]);
            if (temp == a[i]) break;
            a[i] = temp;
        }
        cout << a[n-1] << " ";
    }
    cout << nline;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
