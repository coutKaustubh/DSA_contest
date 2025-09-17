#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    if(!(cin >> T)) return 0;
    while (T--) {
        int N, M;
        cin >> N >> M;
        string S;
        cin >> S;

        int a = 0, b = 0;
        for (char c : S) {
            if (c == '1') ++a;
            else ++b;
        }

        int rem = N - M;
        if (abs(a - b) <= rem && ((a + b + rem) % 2 == 0)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
