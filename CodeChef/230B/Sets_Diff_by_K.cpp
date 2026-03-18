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

void solve() {
    int n, k;
    cin >> n >> k;
    iv(b,n);
    vector<int> S;

    f(i,n) {
        if (b[i] == 1) {
            S.push_back(i + 1);
        }
    }

    
    for (int i = 1; i < S.size(); i++) {
        if (abs(S[i] - S[i - 1]) <= k) {
            no;
            return;
        }
    }

    
    for (int i = 1; i <= n; i++) {
        if (b[i - 1] == 0) {
            bool covered = false;

            
            for (int x : S) {
                if (abs(x - i) <= k) {
                    covered = true;
                    break;
                }
            }

            if (!covered) {
                no;
                return;
            }
        }
    }

    yes;
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