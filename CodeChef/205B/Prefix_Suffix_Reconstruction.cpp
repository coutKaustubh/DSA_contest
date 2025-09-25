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
#define no cout << "No\n"\

void solve() {
       int n; cin >> n;
    vector<int> ans;
    int mxf = 0;

    for(int i=0; i<n; i++) {
        int x; cin >> x;
        if(x) mxf = x;
        if(!i) x -= n;   
        while(x > 0) {
            ans.push_back(i+1);
            x--;
        }
    }

    if(mxf == 1) {
        cout << -1 << "\n";
        
    }
else{
    ans.pop_back();
    ans.push_back(1);
    for(auto &x : ans) cout << x << " ";
    cout << "\n";
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