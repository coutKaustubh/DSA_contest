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

bool possible(ll k, ll s, ll N, ll M) {

    if(k == 0) return s == 0;

    if(M == 1){
        ll low = 2 * k;
        ll high = N * k;

        if(s >= low && s <= high)
            return true;
        else
            return false;
    }

    if(M == N){
        ll low = k;
        ll high = (N-1) * k;

        if(s >= low && s <= high)
            return true;
        else
            return false;
    }

    ll maxC = (s - k) / M;

    ll num = s - k*(M-1);
    ll den = N - M + 1;

    ll minC = 0;

    if(num > 0){
        minC = (num + den - 1) / den;
    }

    ll left = max(0LL, minC);
    ll right = min(k, maxC);

    if(left <= right)
        return true;
    else
        return false;
}

void solve(){
    ll N,K,S,M;
    cin>>N>>K>>S>>M;

    ll l = 0, r = K, ans = K;

    while(l<=r){
        ll mid = (l+r)/2;

        ll remK = K - mid;
        ll remS = S - mid*M;

        if(possible(remK, remS, N, M)){
            ans = mid;
            r = mid-1;
        }
        else
            l = mid+1;
    }

    cout<<ans<<"\n";
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