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
#define endl '\n'
#define yes cout << "Yes\n"
#define no cout << "No\n"





void solve() {
    ll n;
    cin >> n;
    iv(a, n);

    
    if (n==1) {
        cout <<-1<<endl;
        return;
    }

    
    bool allSame = true;
    for (ll i=1;i<n;i++) {
        if (a[i] != a[0]) {
            allSame = false;
            break;
        }
    }

    
    vector<pair<ll,ll>> arr;
    f(i,n) arr.push_back({a[i], i});
    sort(arr.begin(), arr.end());

    
    vector<ll> P(n);
    f(i,n) {
        P[i] = arr[(i+1)%n].second;
    }

    
    f(i,n) {
        if (P[i] == i) {
            swap(P[i], P[(i+1)%n]);
        }
    }

    
    ll c = 0;
    f(i,n) {
        if (a[P[i]]<=a[i])c++;
    }

    cout<<c<<endl;
    f(i,n) cout<< P[i]+1 << " ";
    cout<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) solve();

    return 0;
}
