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


const ll MOD = 1e9 + 7;

struct Matrix {
    ll m[3][3];
};


inline Matrix mul(const Matrix &A, const Matrix &B) {
    Matrix C = {0};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            __int128 sum = 0;
            for (int k = 0; k < 3; ++k)
                sum += (__int128)A.m[i][k] * B.m[k][j];
            C.m[i][j] = (ll)(sum % MOD);
        }
    }
    return C;
}


Matrix power(Matrix base, long long exp) {
    Matrix res = {{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}}; 
    while (exp > 0) {
        if (exp & 1) res = mul(res, base);
        base = mul(base, base);
        exp >>= 1;
    }
    return res;
}


ll tribonacci(long long n) {
    if (n == 1) return 0;
    if (n == 2 || n == 3) return 1;

    Matrix M = {{{1, 1, 1},
                 {1, 0, 0},
                 {0, 1, 0}}};

    Matrix Mp = power(M, n - 3);

    
    ll Tn = (Mp.m[0][0] + Mp.m[0][1]) % MOD;
    return Tn;
}
void solve(){
        ll n;
        cin >> n;
        cout << tribonacci(n) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
