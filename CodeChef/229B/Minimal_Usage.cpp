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

bool can_form(ll tK, ll tS, ll N, ll M) {
    if (tK == 0) return tS == 0;
    if (tS < tK) return false;
    if (M == 1) {
        if (N == 1) return false; 
        return (tS >= 2 * tK && tS <= N * tK);
    }
    if (M == N) {
        return (tS >= 1 * tK && tS <= (N - 1) * tK);
    }

    ll c_max = (tS - tK) / M;

    ll num = tS - tK * (M - 1);
    ll den = N - M + 1;
    ll c_min = 0;
    if (num > 0) {
        c_min = (num + den - 1) / den; 
    }
    return max(0LL, c_min) <= min(tK, c_max);
}

void solve(){
    ll n, k, s, m;
    cin >> n >> k >> s >> m;
    

    for(ll x=0;x<=k;x++){
        ll remK = k-x;
        ll remS = s - x*m;
        if(can_form(remK,remS , n ,m)){
            cout<<x<<endl;
            return;
        }
    }
    
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