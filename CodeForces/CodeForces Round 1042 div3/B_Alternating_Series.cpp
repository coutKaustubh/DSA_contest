#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> res;
    if (n % 2 == 0) {
        for (int i = 0; i < n - 1; ++i) {
            if (i % 2 == 0) {
                res.push_back(-1);
            } else {
                res.push_back(3);
            }
        }
        res.push_back(2);
    } else {
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                res.push_back(-1);
            } else {
                res.push_back(3);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}