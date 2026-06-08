#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f(i,n) for (ll i = 0; i < n; i++)
#define iv(v, n)     \
    vector<ll> v(n); \
    f(i,n) cin >> v[i]

#define INF 1000000000000000000LL
#define nline '\n'

void solve(){
    ll n;
    cin >> n;
    iv(a, n);

    int c1 = 0, c2 = 0;
    f(i,n){
        if(a[i] == 1) c1++;
        else c2++;
    }

    vector<ll> target;

    
    vector<int> pattern = {2,1,2};

    int use1 = 0, use2 = 0;

    for(int i = 0; i < 3 && i < n; i++){
        if(pattern[i] == 2 && c2 > 0){
            target.push_back(2);
            c2--;
            use2++;
        }
        else if(pattern[i] == 1 && c1 > 0){
            target.push_back(1);
            c1--;
            use1++;
        }
        else break;
    }

    
    f(i,n){
        if(a[i] == 1 && use1 > 0){
            use1--;
            continue;
        }
        if(a[i] == 2 && use2 > 0){
            use2--;
            continue;
        }
        target.push_back(a[i]);
    }

    
    vector<int> pos_orig, pos_tar;

    f(i,n){
        if(a[i] == 2) pos_orig.push_back(i);
        if(target[i] == 2) pos_tar.push_back(i);
    }

    ll swaps = 0;
    for(int i = 0; i < pos_orig.size(); i++){
        swaps += abs(pos_orig[i] - pos_tar[i]);
    }

    cout << swaps << nline;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
