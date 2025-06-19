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
    ll N, A, B, C, D;
        cin >> N >> A >> B >> C >> D;

        ll mc = 0;

        f(i,N){
            ll oneCount = N - i;

            ll coin = i * A + oneCount * B;

            if (C >= D) {
               
                ll coins = coin + (i * oneCount * C);
                mc = max(mc, coins);
            } else {
                ll coins = coin + (i * oneCount * D);
                mc = max(mc, coins);
            }
        }

        cout << mc << endl;
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