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
void solve() {
    ll n;cin>>n;

    vector<int>a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];

    vector<int>b(n+1,0);

    for(int i=1;i<=n;i++){
        map<int,int>freq;  
        int one=0;

        for(int j=i;j>=1;j--){
            freq[a[j]]++;

            if(freq[a[j]]==1) one++;
            else if(freq[a[j]]==2) one--;

            if(one==0){
                b[i]=j;
                break;
            }
        }
    }

    vector<int>fr(n+1,0);
    fr[0]=0;

    for(int i=1;i<=n;i++){
        fr[i]=fr[i-1]+1;

        int max_b=INT_MIN;

        for(int j=i;j>=1;j--){
            max_b=max(max_b,b[j]);

            if(max_b<j){
                if(j==1){
                    fr[i]=0;
                }else{
                    fr[i]=min(fr[i],fr[j-2]+1);
                }
            }
        }
    }

    cout<<fr[n]<<"\n";
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