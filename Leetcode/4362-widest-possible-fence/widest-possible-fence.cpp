class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        unordered_map<int,int>mp;

        for(auto x:planks)mp[x]++;
        vector<pair<int,int>>a(mp.begin(),mp.end());
        auto fr = mp; //copy of same map

        for(int i=0;i<a.size();i++){
            auto[x,fx] = a[i];
            // x = a[i].first
            // fx = a[i].second
            for(int j=i+1;j<a.size();j++){
                auto [y,fy] = a[j];
                mp[x+y] += min(fx,fy);
            }
            mp[2*x] += fx/2;
        }
        int mx=0;
        for(auto x:mp){
            mx = max(mx, x.second);
        }
        return mx;
    }
};