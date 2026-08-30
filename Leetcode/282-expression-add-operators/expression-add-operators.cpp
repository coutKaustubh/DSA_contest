class Solution {
public:
    void solve(int curIdx,string sumPath,long sum,long prev, vector<string>&result,string s,int target){
        if(curIdx == s.size() && sum == target){
            result.push_back(sumPath);
            return;
        }
        for(int j = curIdx;j<s.size();j++){
            if (j>curIdx && s[curIdx] == '0')break;

            long num = stol(s.substr(curIdx,j-curIdx+1));
            string tempPath = s.substr(curIdx,j-curIdx+1);

            if(curIdx==0)solve(j+1 , tempPath,num,num,result,s,target);
            else{
                solve(j+1,sumPath+'+'+tempPath,sum+num,num,result,s,target);
                solve(j+1,sumPath+'-'+tempPath,sum-num,-num,result,s,target);
                solve(j+1,sumPath+'*'+tempPath,sum-prev+prev*num,prev*num,result,s,target);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string>result;
        solve(0,"",0,0,result,num,target);
        return result;
    }
};