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

const int MX = 200005;

void solve(){
    ll n;
    cin >> n;

    vector<ll> a(n + 2, 0);
    vector<ll> sfx(n + 2, 0);
    vector<ll> pfmx(n + 2, 0);
    vector<ll> cost(n + 2, 0);       

    for (ll i = 1; i <= n; i++) cin >> a[i];

    sfx[n + 1] = 0;
    for (ll i = n; i >= 1; i--) sfx[i] = sfx[i + 1] + a[i];

    pfmx[0] = 0;
    cost[0] = 0;
    for (ll i = 1; i <= n; i++){
        pfmx[i] = max(a[i], pfmx[i - 1]);
        cost[i] = cost[i - 1] + (pfmx[i] - a[i]);
    }

    ll ans = cost[n];
    ans = min(ans, cost[n - 1]);

    
    vector<ll> stkVal(n + 2, 0);     
    vector<ll> stkCount(n + 2, 0);   
    vector<ll> stkSum(n + 2, 0);     
    vector<ll> prefCount(n + 2, 0);  
    vector<ll> prefvSum(n + 2, 0); 

    ll sz = 0;
    for (ll k = n; k >= 1; k--){
        ll x = a[k], c = 1, s = x;

        while (sz > 0 && stkVal[sz - 1] <= x){
            c += stkCount[sz - 1];
            s += stkSum[sz - 1];
            sz--;
        }

        stkVal[sz] = x;
        stkCount[sz] = c;
        stkSum[sz] = s;
        prefvSum[sz] = (sz > 0 ? prefvSum[sz - 1] : 0) + x * c;
        prefCount[sz]  = (sz > 0 ? prefCount[sz - 1] : 0) + c;
        sz++;

        if (k >= 2){
            ll i = k - 1;
            ll F = pfmx[i - 1];

            
            ll lo = 0, hi = sz - 1, p = -1;
            while (lo <= hi){
                ll mid = (lo + hi) / 2;
                if (stkVal[mid] > F){ p = mid; lo = mid + 1; }
                else hi = mid - 1;
            }

            ll sumMax;
            if (p == -1) sumMax = F * prefCount[sz - 1];
            else sumMax = prefvSum[p] + F * (prefCount[sz - 1] - prefCount[p]);

            ll savedCost = sumMax - sfx[k];
            ll candidate = cost[i - 1] + savedCost;
            if (candidate < ans) ans = candidate;
        }
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