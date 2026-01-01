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

ll getMaxE(vector<ll> a) {
    while (a.size() > 1) {
        int n = a.size();
        ll newVal = a[n-1] * 2 + a[n-2];
        a.pop_back();
        a.pop_back();
        a.push_back(newVal);
    }
    return a[0];
}

ll getMinE(vector<ll> a) {
    while (a.size() > 1) {
        ll newVal = a[0] + a[1] * 2;
        a.erase(a.begin(), a.begin() + 2);
        a.insert(a.begin(), newVal);
    }
    return a[0];
}


void solve(){
    ll n;
    cin>>n;
    iv(a,n);

    ll maxE = getMaxE(a);
    ll minE = getMinE(a);

    cout<<minE<<" "<<maxE<<endl;
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