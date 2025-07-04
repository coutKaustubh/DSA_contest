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
    ll n,k;
    cin>>n,k;
    if(n==k){
        for(int i=1;i<=n;i++)cout<<i<<" ";
        cout<<endl;
    }
    
    else{
        vector<int> perm(n);
    for (int i = 0; i < n; ++i) {
        perm[i] = i + 1;
    }

    int half = k / 2;

    
    vector<int> left(perm.begin(), perm.begin() + half);
    vector<int> middle(perm.begin() + half, perm.end() - half);
    vector<int> right(perm.end() - half, perm.end());

    
    reverse(left.begin(), left.end());
    reverse(right.begin(), right.end());

    
    for (int x : right) cout << x << " ";
    for (int x : middle) cout << x << " ";
    for (int x : left) cout << x << " ";
    cout << endl;

    }
   
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