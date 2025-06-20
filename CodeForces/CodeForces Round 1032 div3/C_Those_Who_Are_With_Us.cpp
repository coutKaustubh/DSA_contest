#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> mat(n, vector<int>(m));
        int mx = INT_MIN;

        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
                mx = max(mx, mat[i][j]);
            }
        }

        
        vector<pair<int,int>> positions;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == mx) {
                    positions.emplace_back(i, j);
                }
            }
        }

        
        bool found = false;
        for (auto &p : positions) {
            int ri = p.first;
            int cj = p.second;
            bool ok = true;
            for (auto &q : positions) {
                int r = q.first, c = q.second;
                if (r != ri && c != cj) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                
                cout << (mx - 1) << "\n";
                found = true;
                break;
            }
        }

        if (!found) {
            
            cout << mx << "\n";
        }
    }

    return 0;
}
