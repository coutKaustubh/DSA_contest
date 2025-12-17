#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    
    ll inside = 0;
    
    
    string temp = s;
    for (int i = 0; i < n; i++) {
        if (temp[i] == 'I') {
            
            if (i > 0 && temp[i-1] != 'I') {
                temp[i] = temp[i-1];
            } 
            
            else if (i < n-1 && temp[i+1] != 'I') {
                temp[i] = temp[i+1];
            } else {
                
                temp[i] = 'A';
            }
        }
    }
    
    
    for (int i = 0; i < n-1; i++) {
        if (temp[i] == temp[i+1]) {
            inside++;
        }
    }

    
    ll boundary = 0;
    if (temp[n-1] == temp[0]) {
        boundary = k - 1;
    }

    cout << inside * k + boundary << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}