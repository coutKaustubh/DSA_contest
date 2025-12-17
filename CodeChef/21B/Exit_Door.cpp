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
    ll n; cin >> n;
    iv(p,n);

    
    vector<ll> pos(n + 1);
    for (ll i = 0; i < n; i++) pos[p[i]] = i;

    set<ll> st;  
    for (int i = 0; i < n; i++) st.insert(i);

    ll total = 0;
    for (ll i = n; i >= 1; i--) {
        ll seat = pos[i];
        auto it = st.find(seat);

        ll left = distance(st.begin(), it);                  
        ll right = distance(next(it), st.end());             
        total += min(left, right);                               

        st.erase(it); 
    }
    cout << total << "\n";
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