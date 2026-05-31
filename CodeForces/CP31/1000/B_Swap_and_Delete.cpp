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
    string s;
        cin >> s;

        int n = s.size();

        int total0 = 0, total1 = 0;
        for(char c : s) {
            if(c == '0') total0++;
            else total1++;
        }

        int prefix0 = 0, prefix1 = 0;
        int max_k = 0;

        for(int k = 1; k <= n; k++) {
            if(s[k-1] == '0') prefix0++;
            else prefix1++;

            int zeros_needed = prefix1; // need opposite
            int ones_needed  = prefix0;

            if(zeros_needed <= total0 && ones_needed <= total1) {
                max_k = k;
            }
        }

        cout << n - max_k << "\n";
  
   
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