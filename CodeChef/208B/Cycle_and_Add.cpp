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

void mt_pdh_bhai(){
    ll n,c;
    cin >> n>>c;        
        iv(b,n);
        iv(d,n);

        vector<ll>dupl=b;
        ll ans= LLONG_MAX;
        ll counter = LLONG_MAX;
       f(i,n) {
            ll sum = c*i;
            f(j,n) sum +=d[j]*dupl[j];
                ans = min(ans, sum);
            f(j,n) {
                ll prev = ((j-i+1)-3+(n+1))%n;
                counter++;
                dupl[j] = min(dupl[j], b[prev]);
            }
        }
        ans = ans^counter;
        counter = ans^counter;
        ans = ans^counter;
        
        cout<<counter<<"\n";
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
        mt_pdh_bhai();
    }

    return 0;
}