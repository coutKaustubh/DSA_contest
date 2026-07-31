class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& it) {
        vector<vector<int>>ans;
        sort(it.begin(), it.end());
        for(int i=0;i<it.size();i++){
            int start = it[i][0];
            int end = it[i][1];
            if(!ans.empty() && end<=ans.back()[1]){
                // ans = [[1,6] , [8,11]]
                // it = [..... [9,10]]
                // so end = 10, start = 9 , and we check end<= ans ke last element ka dusra index i.e 11
                // so if 10<=11 (true) therefore already inside
                continue;
            }
           
                for(int j=i+1;j<it.size();j++){
                    if(it[j][0] <= end){
                        end = max(end , it[j][1]);
                    }
                    else break; // bcz ek bar nhi aaya andar to aage nhi ayega because we sorted whole matrix in start
                }
            ans.push_back({start,end});
        }
        return ans;
    }
};