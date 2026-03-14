#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define f(i, n) for (ll i = 0; i < n; i++)
#define ia(a, n) \
    ll a[n];     \
    f(i, n) cin >> a[i]
#define iv(v, n)     \
    vector<ll> v(n); \
    f(i, n) cin >> v[i]

#define create_matrix(mat, n, m) vector<vector<ll>> mat(n, vector<ll>(m));
#define input_matrix(mat, n, m) f(i, n) f(j, m) cin >> mat[i][j];

#define MOD (1000000007)
#define INF 1000000000000000000LL
#define mp make_pair
#define nline '\n'
#define yes cout << "Yes\n"
#define no cout << "No\n"

void solve(){
    ll n,k,p,m;
    cin>>n>>k>>p>>m;
    iv(a,n);
    p--;
    ll ans = 0;

    while(true){

        int pos = -1;
        f(i,k){
            if(i==p){
                pos = i;
                break;
            }
        }

        if(pos != -1){
            if(m < a[p]) break;

            m -= a[p];
            ans++;

            ll card = a[p];
            a.erase(a.begin()+p);
            a.push_back(card);

            p = n-1;
        }
        else{

            int best = 0;
            for(int i=1;i<k;i++){
                if(a[i] < a[best]) best = i;
            }

            if(m < a[best]) break;


            m -= a[best];

            ll card = a[best];
            a.erase(a.begin()+best);
            a.push_back(card);

            if(best < p) p--;
        }
    }

    cout<<ans<<"\n";
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}