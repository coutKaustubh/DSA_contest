#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        int N; cin >> N;
        vector<ll> A(N);
        for (int i = 0; i < N; ++i) cin >> A[i];

        
        vector<ll> vals = A;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        int bestKeep = 1; 

        for (ll v : vals) {
            int cnt = 0;
            ll cur = 0;
            bool hasEligible = false; 
            for (int i = 0; i < N; ++i) {
                cur += A[i];
                if (A[i] <= v) hasEligible = true;
                if (cur >= v && hasEligible) {
                    
                    ++cnt;
                    cur = 0;
                    hasEligible = false;
                }
            }
            bestKeep = max(bestKeep, cnt);
        }

        cout << (N - bestKeep) << "\n";
    }
    return 0;
}
