#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define yes cout << "YES\n"
#define no cout << "NO\n"

void solve() {
    ll l1,b1,l2,b2,l3,b3;
    cin>>l1>>b1>>l2>>b2>>l3>>b3;

    
    vector<pair<ll,ll>> rects;
    rects.push_back({l1, b1});
    rects.push_back({l2, b2});
    rects.push_back({l3, b3});

    
    sort(rects.begin(), rects.end());

    
    ll lA = rects[0].first, bA = rects[0].second;
    ll lB = rects[1].first, bB = rects[1].second;
    ll lC = rects[2].first, bC = rects[2].second;

    
    if (lA == lB && lB == lC && bA + bB + bC == lA) {
        yes; return;
    }

    
    if (bA == bB && bB == bC && lA + lB + lC == bA) {
        yes; return;
    }

    
    if ((bA == bB) && (lA + lB == lC) && (bA + bC == lC)) {
        yes; return;
    }

    
    if ((lA == lB) && (bA + bB == bC) && (lA + lC == bC)) {
        yes; return;
    }

    no;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
