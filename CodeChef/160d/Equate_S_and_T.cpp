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
    ll n,m;
    cin>>n>>m;
    string s,t;
    cin>>s>>t;

    if(s[0] != t[0])no;
    else{
    iv(b_after_a_inS,n);   
    iv(b_after_a_inT,m);
    ll c= 0;
    for(int i = n-1; i>=0; i--){
        if(s[i]=='b'){
            b_after_a_inS[i]=-1;
            c++;
        }
        if(s[i] == 'a'){
            b_after_a_inS[i] = c;
            c=0;
        }
    }   
    c=0;
    for(int i = m-1; i>=0; i--){
        if(s[i]=='b'){
            b_after_a_inT[i]=-1;
            c++;
        }
        if(s[i] == 'a'){
            b_after_a_inT[i] = c;
            c=0;
        }
    }
    vector<int>index1;
    vector<int>index2;
    ll c_a_inS=0,c_a_inT=0;
    f(i,n){
        if(s[i] == 'a')c_a_inS++;
        if(b_after_a_inS[i] != -1){
            index1.push_back(i);
        }
    }   
    f(i,m){
        if(t[i]=='a')c_a_inT++;
        if(b_after_a_inT[i] != -1){
            index2.push_back(i);
        }
    }  
    if((c_a_inS == 0 && c_a_inT==0) || ( c_a_inS != c_a_inT))no;
    else if(index1 == index2)yes;
    else no;
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