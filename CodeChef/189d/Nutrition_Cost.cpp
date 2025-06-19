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
#define MOD (1000000007)
#define INF 1000000000000000000LL // Infinity for ll
#define mp make_pair
#define nline '\n'
#define yes cout << "YES\n"
#define no cout << "NO\n"

void solve(){
    int n, c;
    cin >> n >> c;
    vector<int> a(n), b(n);
    unordered_map<int, int> mp;

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    
    for(int i = 0; i < n; i++) {
        int vm = a[i];
        int cost = b[i];
        if(mp.find(vm) == mp.end()) mp[vm] = cost;
        else mp[vm] = min(mp[vm], cost);
    }

    
    vector<int> cst;
    for(auto &[vit,cost] : mp) {
        cst.push_back(cost);
    }

    sort(cst.begin(), cst.end());  

    int mx = 0, sum = 0;
    for(int i = 0; i < cst.size(); i++) {
        sum += cst[i];        
        int x = i + 1;          
        mx = max(mx, c * x - sum);
    }

    cout << mx << endl;
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