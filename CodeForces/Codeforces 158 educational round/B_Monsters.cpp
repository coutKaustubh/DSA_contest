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

bool cmp(pair<int,int>a, pair<int,int>b){
    if(a.first != b.first)return a.first>b.first; 
    return a.second<b.second;
}

void solve(){
    ll n;
    cin>>n;
    ll k;
    cin>>k;
    iv(a,n);
    f(i,n){
        a[i]%=k;
    }
    vector<pair<int,int>>v(n);
    f(i,n){
        v[i].first = a[i];
        v[i].second = i+1;
    }
    sort(v.begin(),v.end(),cmp);

    
    vector<int> zero;
    vector<int> other;

    
    for(auto &p : v){
        if(p.first == 0) zero.push_back(p.second);
        else other.push_back(p.second);
    }

    
    sort(zero.begin(), zero.end());
    for(int idx : zero) cout << idx << " ";

    
    for(int idx : other) cout << idx << " ";
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