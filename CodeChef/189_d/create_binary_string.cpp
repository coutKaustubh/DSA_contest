#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N, A, B, C, D;
        cin >> N >> A >> B >> C >> D;

        int mc = 0;

        for (int i = 0; i <= N; ++i) {
            int oneCount = N - i;

            int coin = i * A + oneCount * B;

            if (C >= D) {
               
                int coins = coin + (i * oneCount * C);
                mc = max(mc, coins);
            } else {
                int coins = coin + (i * oneCount * D);
                mc = max(mc, coins);
            }
        }

        cout << mc << endl;
    }
    return 0;
}
