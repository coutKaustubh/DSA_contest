#include <bits/stdc++.h>



using namespace std;


#define ll long long
#define f(i,n) for(ll i=0;i<n;i++)
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

void solve() {
    ll n;
    cin >> n;
    iv(arr, n);

    vector<ll> a = arr;
    sort(a.begin(), a.end());

    vector<ll> ans(n, 0);
    ll prev = a[0];

    unordered_map<ll,ll>valToSum;
    valToSum[a[0]] = -1;          
    valToSum[a[n-1]] = -1;          

    for (ll i = 1; i < n - 1; i++) {
        ll sum = 0;
        ll mid1 = (prev + a[i]) / 2;
        sum += abs(a[i] - mid1);
        ll mid2 = (a[i] + a[i + 1]) / 2;
        sum += abs(a[i] - mid2);
        valToSum[a[i]] = sum;
        prev = a[i];
    }

    f(i,n) {
        ans[i] = valToSum[arr[i]];
    }

    f(i,n) cout<< ans[i] << " ";
    cout << "\n";
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