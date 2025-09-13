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

    

#define INF 1000000000000000000LL 
#define mp make_pair
#define nline '\n'
#define yes cout << "Yes\n"
#define no cout << "No\n"
const ll MOD = 998244353;
long long floor_sum(long long n, long long m, long long a, long long b) {
    long long ans = 0;
    while (true) {
        if (a >= m) {
            ans += (n - 1) * n * (a / m) / 2;
            a %= m;
        }
        if (b >= m) {
            ans += n * (b / m);
            b %= m;
        }
        long long y_max = a * n + b;
        if (y_max < m) break;
        n = y_max / m;
        b = y_max % m;
        swap(m, a);
    }
    return ans;
}


vector<int> get_cycles(const vector<int>& P) {
    int N = P.size();
    vector<int> vis(N, 0);
    vector<int> cycles;
    for (int i = 0; i < N; i++) {
        if (!vis[i]) {
            int len = 0, j = i;
            while (!vis[j]) {
                vis[j] = 1;
                j = P[j] - 1;
                len++;
            }
            if (len > 1) cycles.push_back(len); 
        }
    }
    return cycles;
}


long long cycle_contribution(int L, int N) {
    long long res = 0;

    
    for (int A = 1; A <= N; A++) {
        long long K = (long long) L * A / (L - 1); 
        if (K > N) K = N;
        long long part1 = (L - 1) * (K * (K + 1) / 2 % MOD) % MOD;
        long long part2 = ((N - K) % MOD) * ((1LL * L * A) % MOD) % MOD;
        res = (res + part1 + part2) % MOD;
    }

    return res;
}



void solve(){
    int N;
        cin >> N;
        vector<int> P(N);
        for (int i = 0; i < N; i++) cin >> P[i];

        vector<int> cycles = get_cycles(P);

        long long ans = 0;
        for (int L : cycles) {
            ans = (ans + cycle_contribution(L, N)) % MOD;
        }
        cout << ans << "\n";
    

   
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