class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        vector<int>ans;
        int n = mat.size();
        int m = mat[0].size();
        int top=0,left=0,right=m-1,bottom=n-1; //these are direcions where index will move
        //i.e. left to right , top to bottom , bottom to top aise ....

        while(top<=bottom && right>=left){
            for(int i=left;i<=right;i++){
                ans.push_back(mat[top][i]);
            }
            top++;

            for(int i=top;i<=bottom;i++){
                ans.push_back(mat[i][right]);
            }
            right--;
            if(top<=bottom){
            for(int i=right;i>=left;i--){
                ans.push_back(mat[bottom][i]);
            }
            bottom--;
            }

            if(left<=right){
            for(int i = bottom;i>=top;i--){
                ans.push_back(mat[i][left]);
            }
            left++;
            }
        }
        return ans;
    }
};