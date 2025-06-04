#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int>v(n);
	    unordered_map<int,int>m;
	    for(int i=0;i<n;i++){
	        cin>>v[i];
	        m[v[i]]++;
	    }
	    int c = 0;
	    for(auto &val : m){
	        c++;
	    }
	    if(c>1)cout<<2<<endl;
	    else{
	        cout<<-1<<endl;
	    }
	}

}
