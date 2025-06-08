#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>a(n);
    map<int,int>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        m[a[i]]++;
    }
    int maxFreq = 0;
    int maxElem = -1;
    bool allOne = true;

    for (auto [val, freq] : m) {
        if (freq > 1) allOne = false;
        if (freq > maxFreq) {
            maxFreq = freq;
            maxElem = val;
        }
    }
    
    if(allOne)cout<<1<<endl;
    else{
        if(v[0] == maxElem){
            cout<<maxFreq<<endl;
        }
    }


}

int main(){
 int t;
 cin>>t;
 while(t--){
 solve();
 }  
}