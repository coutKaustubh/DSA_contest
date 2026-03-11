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

// ll secondMaxIndex(vector<ll> &a)
// {
//     ll max1 = ll_MIN, max2 = ll_MIN;
//     ll index1 = -1, index2 = -1;

//     for(ll i = 0; i < a.size(); i++)
//     {
//         if(a[i] > max1)
//         {
//             max2 = max1;
//             index2 = index1;

//             max1 = a[i];
//             index1 = i;
//         }
//         else if(a[i] > max2 && a[i] != max1)
//         {
//             max2 = a[i];
//             index2 = i;
//         }
//     }

//     return index2;
// }

void solve()
{
    ll n;
    cin >> n;
    iv(a,n);
    vector<ll> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](ll x, ll y){
            return a[x] < a[y];
        });
        
        ll i = idx[n-2], j = idx[n-1], k = idx[0];
        if(a[i] + a[j] != a[k]){
            cout << i+1 << " " << j+1 << " " << k+1 << "\n";
            return;
        }
        
        i = idx[0]; j = idx[1]; k = idx[n-1];
        if(a[i] + a[j] != a[k]){
            cout << i+1 << " " << j+1 << " " << k+1 << "\n";
            return;
        
        }
        
        cout << -1 << "\n";
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