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
    ll n,k;
    cin>>n>>k;


    iv(a,n);
    ll sum=0;
    f(i,n){
        sum+=a[i];
    }
    sort(a.begin(),a.end());
    ll min1 = a[0],min2=a[1];
    sum+=(min1+min2+1)/2;
    while(k--){
       ll avg = (min1+min2+1)/2;
       if(avg<min2){
        sum+=avg;
        min2=avg;
        k--;
       }
       else{
        sum+=avg*k;
        break;
       }

    }

    cout<<sum<<endl;
   
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