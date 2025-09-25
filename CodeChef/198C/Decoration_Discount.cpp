#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);

        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        int minC = INT_MAX;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j) continue;
                int cost = A[i];
                if (i + 1 == j) cost += A[j] / 2;
                else if (j + 1 == i) cost = A[i] / 2 + A[j];
                else cost += A[j]; 

                minC = min(minC, cost);
            }
        }

        cout << minC << endl;
    }

    return 0;
}
