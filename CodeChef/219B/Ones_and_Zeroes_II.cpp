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
    ll n;
    cin>>n;
    string s;
    cin>>s;
    
    ll c1 = 0, c0 = 0;
        for (char c : s) {
            if (c == '1') c1++;
            else c0++;
        }

        
        ll L = (c1 >= c0 ? n : 2 * c1);

        
        vector<int> pos1, pos0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') pos1.push_back(i);
            else pos0.push_back(i);
        }

        int p1 = 0, p0 = 0;
        ll balance = 0;

        vector<int> posOne_target;

        
        for (int i = 0; i < L; i++) {
            if (balance == 0) {
                posOne_target.push_back(i);
                balance++;
                p1++;
            } else {
                
                if (p0 < (int)pos0.size() &&
                    (p1 >= (int)pos1.size() || pos0[p0] < pos1[p1])) {
                    
                    balance--;
                    p0++;
                } else {
                    
                    posOne_target.push_back(i);
                    balance++;
                    p1++;
                }
            }
        }

        
        ll swaps = 0;
        for (int i = 0; i < (int)posOne_target.size(); i++) {
            swaps += llabs(pos1[i] - posOne_target[i]);
        }

        cout << L << " " << swaps << '\n';
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