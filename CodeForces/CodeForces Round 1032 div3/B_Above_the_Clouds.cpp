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
#define MOD (1000000007)
#define INF 1000000000000000000LL // Infinity for ll
#define ump unordered_map
#define mp map 
#define nline '\n'
#define yes cout << "Yes\n"
#define no cout << "No\n"

void solve(){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ump<char,int>u;
    f(i,n){
        u[s[i]]++;
    }
 
    for(auto &m : u){
        if(m.second == 2){
            if(s[0] == m.first && s[n-1] == m.first){
                
            }
            else{
                yes;
                return;
            }
        }
        if(m.second > 2){
            yes;
            return;
        }
    }
    for (int i = 1; i < n - 1; ++i) {
        string a = s.substr(0, i);
        string c = s.substr(i + 1);
        string ac = a + c;
        if (ac.find(s[i]) != string::npos) {
            yes;
            return;
        }
    }   

    no;
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