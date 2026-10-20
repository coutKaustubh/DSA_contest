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

int p[1000005];
int fun(int x){
    return p[x] == x ? x : p[x] = fun(p[x]);
}
void solve(){
    ll n,m;
    cin>>n>>m;
    vector<vector<pair<int,ll>>>g(n+1);
    f(i,m){
        ll u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});


    }
    vector<int>cnt(n+1,0);
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;
    pq.push({0,1});
    while(!pq.empty()){
        ll d = pq.top().first;
        ll u = pq.top().second;
        pq.pop();
        if(cnt[u] >= 2)continue;
        cnt[u]++;

        if(u==n && cnt[u]==2){
            cout<<d<<nline;
            return;
        }
        for(auto x:g[u]){
            ll v = x.first;
            ll w = x.second;
            pq.push({d+w,v});
        }
    }
    cout<<-1<<nline;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    

    return 0;
}