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
    ll q;
    cin>>q;
    iv(a,n);
    iv(b,n);
    f(i,n){
        a[i] = max(a[i],b[i]);
    }
    for (int i = n - 1; i > 0; i--) {
        a[i - 1] = max(a[i - 1], a[i]);
    }
    vector<ll> pref(n);
    pref[0] = a[0];
    for (int i = 1; i < n; i++) {
        pref[i] = pref[i - 1] + a[i];
    }
    while(q--){
        ll l,r;
        cin>>l>>r;
        l--; r--;

        ll sum = pref[r] - (l > 0 ? pref[l - 1] : 0);
        cout << sum << " ";

    }
    cout<<endl;
   
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