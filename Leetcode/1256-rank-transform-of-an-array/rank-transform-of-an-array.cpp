class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n =arr.size();
        priority_queue<int , vector<int>, greater<int>>minH;
        for(int i=0;i<arr.size();i++){
            minH.push(arr[i]);
        }
        unordered_map<int,int>mp;
        int i=0;
        vector<int>ans;
        while(!minH.empty()){
            int top = minH.top();
            minH.pop();
            if(!mp.count(top)){
                i+=1;
                mp[top] = i;
            }
        }
        for(int i:arr){
            ans.push_back(mp[i]);
        }
        return ans;
    }
};