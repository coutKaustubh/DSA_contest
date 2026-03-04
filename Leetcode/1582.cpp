#define f(i,n) for (int i = 0; i < n; i++)

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int sum=0;
        f(i,mat.size()){
        int cR=0,cC=0,index=-1;
            f(j,mat[0].size()){
                if(mat[i][j]==1){  
                    index=j;
                    cR++;
                }
            }

            if(cR==1){
                for(int r=0;r<mat.size();r++){
                    if(mat[r][index]==1) cC++;
                }

                if(cC==1) sum++;

                cR=0;
                cC=0;
            }
        }

        return sum;
    }
};