class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>diff(arr.size(),0);
        for(int i=0;i<arr.size();i++){
            diff[i] = abs(x - arr[i]);
        }
        priority_queue<pair<int,int>>maxheap;
        int i=0;
        for(auto x:diff){
            maxheap.push({x,i});
            i++;
            if(maxheap.size() > k)maxheap.pop();
        }
        i=0;

        vector<int>ans;
        while(!maxheap.empty()){
            ans.push_back(arr[maxheap.top().second]);
            maxheap.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;


    }
};