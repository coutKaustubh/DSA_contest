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
    ll R, G, B;
    cin >> R >> G >> B;

    vector<pair<ll,char>> a = {
        {R,'R'}, {G,'G'}, {B,'B'}
    };

    string ans = "";

    while(true){
        sort(a.begin(), a.end(), greater<>());

        bool placed = false;

        for(int j = 0; j < 3; j++){
            if(a[j].first == 0) continue;

            char ch = a[j].second;
            int i = ans.size();

            if(i-1 >= 0 && ans[i-1] == ch) continue;
            if(i-3 >= 0 && ans[i-3] == ch) continue;

            ans.push_back(ch);
            a[j].first--;
            placed = true;
            break;
        }

        if(!placed) break; 
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