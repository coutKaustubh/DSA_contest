class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int r = n*m-1;
        while(l<=r){
            int mid = (l+r)/2;
            int i = mid/m;
            int j =mid%m;

            if(matrix[i][j] == target)return true;
            else if(matrix[i][j] > target)r=mid-1;
            else l=mid+1;

        }
        return false;
    }
};