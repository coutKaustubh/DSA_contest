#include <iostream>
using namespace std;
/*
Given an integer N, consider all arrays A of size N such that:

1) All the elements are non-negative and distinct.
2) All prefix sums are odd.
Formally, for all 𝑖 such that  summation of  j=1 to i Aj is odd

*/

//  1<=N<=pow(10,9)

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //if not write above tow lines

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long sum = n*(n-3) + 3;
        cout << sum << "\n";
    }
    return 0;
}