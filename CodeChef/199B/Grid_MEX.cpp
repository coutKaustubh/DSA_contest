#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int mex(const unordered_set<int>& s) {
    int m = 0;
    while (s.count(m)) {
        m++;
    }
    return m;
}

void constructGrid(int N) {
    vector<vector<int>> grid(N, vector<int>(N));
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            unordered_set<int> v_ij;
            for (int k = 0; k < N; ++k) {
                if (k != j) {
                    v_ij.insert(grid[i][k]);
                }
                if (k != i) {
                    v_ij.insert(grid[k][j]);
                }
            }
            grid[i][j] = mex(v_ij);
        }
    }
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        constructGrid(N);
    }
    return 0;
}