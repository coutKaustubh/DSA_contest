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
    iv(a,n);
    unordered_map<int,int>mp;
    f(i,n){
        mp[a[i]]++;

    }
    ll c = 0,s1,s2;
    bool one= false,three=false;
    for(auto &val : mp){
        if(val.first == 2 && val.second > 1){
            c+=val.second - 1;
        }
        if(val.first == 1){
            one = true;
            s1 = val.second;
        }
        if(val.first == 3){
            three = true;
            s2 = val.second;
        }
        if((val.first == 1 && three) || (val.first == 3 && one)){
            c+=min(s1,s2);
        }
    }
    cout<<c<<endl;
   
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