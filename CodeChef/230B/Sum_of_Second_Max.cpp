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

// void solve(){
//     ll n;
//     cin>>n;
//     iv(a,n);
//     ll sum=0;
//     f(i,n-1){
//         sum+=a[i]*(i+1);
//     }
//     cout<<sum<<endl;
   
// }    
void solve(){
    ll n;cin>>n;
    iv(a,n);

    vector<pair<ll,ll>> v;
    f(i,n) v.push_back({a[i],i});

    sort(v.rbegin(),v.rend());

    set<ll> s;
    ll ans=0;

    for(auto it:v){
        ll val=it.first,pos=it.second;

        s.insert(pos);
        auto itr=s.find(pos);

        ll L1=-1,L2=-1,R1=n,R2=n;

        if(itr!=s.begin()){
            auto it1=prev(itr);
            L1=*it1;
            if(it1!=s.begin()){
                auto it2=prev(it1);
                L2=*it2;
            }
        }

        auto it1=next(itr);
        if(it1!=s.end()){
            R1=*it1;
            auto it2=next(it1);
            if(it2!=s.end()){
                R2=*it2;
            }
        }

        ll left=(L1-L2)*(R1-pos);
        ll right=(pos-L1)*(R2-R1);

        ans+=(left+right)*val;
    }

    cout<<ans<<"\n";
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