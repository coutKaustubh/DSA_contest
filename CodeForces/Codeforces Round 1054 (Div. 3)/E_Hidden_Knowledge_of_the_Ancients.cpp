#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 

#define f(i,n) for (ll i = 0; i < n; i++)
#define ia(a,n) \
    ll a[n]; f(i,n) cin >> a[i]
#define iv(v,n) \
    vector<ll> v(n); f(i,n) cin >> v[i]


ll countAtMostKDistinct(vector<ll>& a, ll k, ll l, ll r) {
    unordered_map<ll,ll> freq;
    ll b = 0, count = 0, distinct = 0;
    for (ll c = 0; c < a.size(); c++) {
        freq[a[c]]++;
        if (freq[a[c]] == 1) distinct++;

        while (distinct > k || (c - b + 1) > r) {
            freq[a[b]]--;
            if (freq[a[b]] == 0) distinct--;
            b++;
        }

        if (c - b + 1 >= l) {
            count += (c - b + 1 - l + 1);
        }
    }
    return count;
}

ll countExactlyKDistinct(vector<ll>& a, ll k, ll l, ll r) {
    if(k==0) return 0;
    return countAtMostKDistinct(a, k, l, r) - countAtMostKDistinct(a, k-1, l, r);
}


void solve(){
      ll n, k, l, r;
        cin >> n >> k >> l >> r;
        vector<ll> a(n);
        for(ll i=0;i<n;i++) cin >> a[i];

        cout << countExactlyKDistinct(a, k, l, r) << "\n";
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