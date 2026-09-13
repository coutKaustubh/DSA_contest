class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& it) {
        if(it.size()==1)return it;
        vector<vector<int>>ans;
        sort(it.begin(), it.end());
        int start = it[0][0];
        int end = it[0][1];
        int i=1;
        while(i<it.size()){
            if(it[i][0] <= end){
                end = max(end,it[i][1]);
            }
            else{
                ans.push_back({start,end});
                start = it[i][0];
                end = it[i][1];
            }
            i++;
        }
        ans.push_back({start, end});
        return ans;
    }
};