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

void solve(){
    ll n, m;
    cin >> n >> m;
    if(m<n){cout<<m<<" "<<m+1<<"\n"; return;}
    if(m<=n && n>=2){cout<<m-1<<" "<<m<<"\n"; return;}


    for(ll i = 2; i <= 31; i++){

            ll power = (1LL << i) - 1;
            ll rem = m%power;
            ll firstVal;
            if(rem == 0)firstVal = power;
            else firstVal = rem;
            int k = m-n;
            k++;
            if(m>firstVal){
                ll secondVal = firstVal + (m-firstVal)/power;
                if(secondVal <= n){
                    cout<<firstVal<<" "<<secondVal<<"\n";
                    return;
                }
            }
    }

    cout << -1 << "\n";
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