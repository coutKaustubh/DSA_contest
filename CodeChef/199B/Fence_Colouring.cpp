#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<long long> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        unordered_map<long long, long long> freq;
        for (auto a : A) {
            freq[a]++;
        }

        long long f1 = freq[1]; 
        long long maxf = 0;     
        for (auto &p : freq) {
            maxf = max(maxf, p.second);
        }

        long long ans = min((long long)N - f1, (long long)N - maxf + 1);
        cout << ans << "\n";
    }
    return 0;
}
