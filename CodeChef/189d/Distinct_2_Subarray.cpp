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
#define mp make_pair
#define nline '\n'
#define yes cout << "YES\n"
#define no cout << "NO\n"

void solve(){
    int n;
	    cin>>n;
	    vector<int>v(n);
	    unordered_map<int,int>m;
	    for(int i=0;i<n;i++){
	        cin>>v[i];
	        m[v[i]]++;
	    }
	    int c = 0;
	    for(auto &val : m){
	        c++;
	    }
	    if(c>1)cout<<2<<endl;
	    else{
	        cout<<-1<<endl;
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