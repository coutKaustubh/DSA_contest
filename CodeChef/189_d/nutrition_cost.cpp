#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, c;
    cin >> n >> c;
    vector<int> a(n), b(n);
    unordered_map<int, int> mp;

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    
    for(int i = 0; i < n; i++) {
        int vm = a[i];
        int cost = b[i];
        if(mp.find(vm) == mp.end()) mp[vm] = cost;
        else mp[vm] = min(mp[vm], cost);
    }

    
    vector<int> cst;
    for(auto &[vit,cost] : mp) {
        cst.push_back(cost);
    }

    sort(cst.begin(), cst.end());  

    int mx = 0, sum = 0;
    for(int i = 0; i < cst.size(); i++) {
        sum += cst[i];        
        int x = i + 1;          
        mx = max(mx, c * x - sum);
    }

    cout << mx << endl;
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    solve();
	}

}
