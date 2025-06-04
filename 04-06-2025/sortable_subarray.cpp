#include<bits/stdc++.h>

using namespace std;

int x1(const vector < int > & a1, int b1, int c1) {
    int d1 = -1;
    for (int e1 = b1; e1 <= c1; e1++) {
        int f1 = a1[e1];
        int g1 = (f1 - 1) / 2;
        int h1 = d1 + 1;
        if (h1 <= g1) {
            d1 = h1;
        }
        else if (f1 > d1) {
            d1 = f1;
        }
        else {
            return 0;
        }
    }
    return 1;
}

long long y1(int z1,
    const vector < int > & j1) {
    long long k1 = 0;
    for (int l1 = 0; l1 < z1; l1++) {
        for (int m1 = l1; m1 < z1; m1++) {
            k1 += x1(j1, l1, m1);
        }
    }
    return k1;
}

int main() {
    int n1;
    cin >> n1;
    while (n1--) {
        int o1;
        cin >> o1;
        vector < int > p1(o1);
        for (int q1 = 0; q1 < o1; q1++) {
            cin >> p1[q1];
        }
        cout << y1(o1, p1) << endl;
    }
    return 0;
}