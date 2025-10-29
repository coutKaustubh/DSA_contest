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
    ll balance = 0;
    vector<ll> bad; 

    f(i,n){
        if (s[i] == '0') balance++;
        else balance--;

        if (balance < 0) { 
            balance = 0;
            bad.push_back(i);
        }
    }
        
    for (int i = n - 1; i >= 0 && balance>0; --i) {
        if (s[i] == '0') {
            bad.push_back(i);
            balance--;
        }
    }
    if (bad.empty()){
        cout<<0<<endl; 
        return;
    } 
     bool oneSeen = false, mixed = false;
    f(i,n){
        if (find(bad.begin(), bad.end(), i) != bad.end()) {
            if (s[i] == '1') oneSeen = true;
            if (s[i] == '0' && oneSeen) {
                mixed = true;
                break;
            }
        }
    }

    if(mixed)cout<<2<<endl;
    else cout<<1<<endl;
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