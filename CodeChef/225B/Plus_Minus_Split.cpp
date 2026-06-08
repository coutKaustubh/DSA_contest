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

bool allEqual(vector<ll>& a) {
    for (int i = 1; i < a.size(); i++) {
        if (a[i] != a[0])
            return false;
    }
    return true;
}

void solve() {
    ll n;
    cin >> n;
    iv(a,n);

    if (allEqual(a)) {
        cout << "Yes\n";
        return;
    }

    if(a[0]<0){
        f(i,n){
            if(a[i] < 0)a[i]=a[i]*-1;
            else break;
        }
    }
    else if(a[n-1] < 0){
        for(int i=n-1;i>=0;i--){
            if(a[i]<0)a[i]=a[i]*-1;
            else break;
        }
    }
    if(allEqual(a))yes;
    else no;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
