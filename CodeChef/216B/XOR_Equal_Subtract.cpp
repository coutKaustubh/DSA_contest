

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


void dekhlebhai(){
    int N; cin >> N;
        unordered_map<ll,int> cnt;
        cnt.reserve(N*2);
        for(int i=0;i<N;++i){
            ll x; cin >> x;
            ++cnt[x];
        }

        
        vector<ll> masks;
        masks.reserve(cnt.size());
        for(auto &p : cnt) masks.push_back(p.first);

        
        sort(masks.begin(), masks.end(), [](ll a, ll b){
            int pa = ountll(a);
            int pb = __builtin_popcountll(b);
            if(pa != pb) return pa < pb;
            return a < b;
        });

        int M = masks.size();
        if(M == 0){
            cout << 0 << '\n';
        }

        
        vector<int> dp(M);
        int ans = 0;
        for(int i=0;i<M;++i){
            dp[i] = cnt[masks[i]]; 
            for(int j=0;j<i;++j){
                
                if((masks[i] & masks[j]) == masks[j]){
                    dp[i] = max(dp[i], dp[j] + cnt[masks[i]]);
                }
            }
            ans = max(ans, dp[i]);
        }
        cout << ans << '\n';
   
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
        dekhlebhai();
    }

    return 0;
}



