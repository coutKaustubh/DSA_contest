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

void solve() {
    int n;
    ll m;
    cin >> n >> m;

    vector<pair<ll,int>> req(n);
    f(i,n) {
        cin >> req[i].first >> req[i].second;
    }

    ll currTime = 0;
    int currSide = 0; 
    ll points = 0;

    f(i,n) {
        ll nextTime = req[i].first;
        int reqSide = req[i].second;

        ll gap = nextTime - currTime;
        int d = abs(reqSide - currSide); 

        ll moves = gap;
        if ((gap - d) % 2 != 0) {
            moves--; 
        }
        points += moves;

        currTime = nextTime;
        currSide = reqSide;
    }

    
    ll gap = m - currTime;
    points += gap;

    cout << points << nline;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
