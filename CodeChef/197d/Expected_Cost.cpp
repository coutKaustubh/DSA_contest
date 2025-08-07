#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> B[i];
    
    vector<double> dp(N + 2);
    dp[N + 1] = 0.0;
    
    double low = 0.0, high = 1e12;
    double ans = 0.0;
    const double eps = 1e-10;
    
    for (int iter = 0; iter < 100; ++iter) {
        double mid = (low + high) / 2;
        double sum = 0.0;
        for (int x = N; x >= 1; --x) {
            double cost_move = A[x - 1] + dp[x + 1];
            double cost_teleport = B[x - 1] + mid;
            dp[x] = min(cost_move, cost_teleport);
            sum += dp[x];
        }
        sum += dp[N + 1]; 
        double current_S = sum / (N + 1);
        if (abs(current_S - mid) < eps) {
            ans = mid;
            break;
        }
        if (current_S < mid) {
            high = mid;
        } else {
            low = mid;
        }
    }
    
    
    for (int x = N; x >= 1; --x) {
        double cost_move = A[x - 1] + dp[x + 1];
        double cost_teleport = B[x - 1] + ans;
        dp[x] = min(cost_move, cost_teleport);
    }
    
    cout << fixed << setprecision(10) << dp[1] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    
    return 0;
}