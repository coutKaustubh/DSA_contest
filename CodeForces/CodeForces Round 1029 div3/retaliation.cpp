#include<bits/stdc++.h>
using namespace std;

bool checkOrder(const vector<int>& v) {
    bool asc = true, desc = true;
    for (size_t i = 1; i < v.size(); i++) {
        if (v[i] > v[i-1]) desc = false;
        else if (v[i] < v[i-1]) asc = false;
    }
    if (asc || desc) return true;
    else return false;
}

void solve(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<int>diff;
    if(checkOrder(v)){
        int sum=0;
        for(int i=1;i<n;i++){
            diff.push_back(v[i]-v[i-1]);
            sum+=v[i]-v[i-1];
        }
        if(diff[0]*diff.size() == sum){
            
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