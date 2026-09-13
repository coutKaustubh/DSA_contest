class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size();
        //transpose matrix  and reverse each row

        /*
        1 2 3                   1 4 7               7 4 1
        4 5 6   ---transpose--- 2 5 8 ---reverse--- 8 5 2 
        7 8 9                   3 6 9               9 6 3 
        */

        // so to transpose swap elements

        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                swap(mat[i][j] , mat[j][i]);
            }
        }
        for(int i=0;i<n;i++){
            reverse(mat[i].begin(),mat[i].end());
        }


    }
};