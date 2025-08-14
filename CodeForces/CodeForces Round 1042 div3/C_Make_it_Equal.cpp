#include <bits/stdc++.h>
using namespace std;

#define yes cout << "YES\n";
#define m1 cout << "-1\n";
#define no cout << "NO\n";
typedef long long ll;


int main() {

  int t;
    cin>>t;
  while (t--) {
    int n;
    ll k;
    cin >> n >> k;
    vector<ll>s(n);
    vector<ll>t(n);
    for(int i=0;i<n;i++)cin>>s[i];
    for(int i=0;i<n;i++)cin>>t[i];
    if (k == 0) {
      sort(s.begin(),s.end());
      sort(t.begin(),t.end());
      if (s == t) yes 
      else no
      continue;
    }
    unordered_map<ll,int> count;
    for (auto &x : s) {
      ll r = x % k;
 
      ll nr = min(r, k - r);
      count[nr]++;
    }
    for (auto &x : t) {
      ll r = x % k;
        ll nr = min(r, k - r);
      count[nr]--;
    }
    bool ok = true;
    for (auto &p : count) {
        if (p.second != 0) { 
        ok = false; 
        break; 
        }
    }
    if (ok) yes
     else no
  }
  return 0;
}
