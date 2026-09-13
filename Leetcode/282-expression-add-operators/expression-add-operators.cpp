class Solution {
public:
    void solve(int curIdx,string finalPath,long final,long prev, vector<string>&ans,string s,int target){
        if(curIdx == s.size() && final == target){
            ans.push_back(finalPath);
            return;
        }

        for(int j = curIdx;j<s.size();j++){
            if (j>curIdx && s[curIdx] == '0')break; //leading 0 uda do
            long num = stol(s.substr(curIdx,j-curIdx+1));
            string tempPath = s.substr(curIdx,j-curIdx+1);
            if(curIdx == 0)solve(j+1 ,tempPath,num,num,ans,s,target);
            else{
                //+
                solve(j+1 ,finalPath+"+"+tempPath,num+final,num,ans,s,target);
                solve(j+1 ,finalPath+"-"+tempPath,final-num,-num,ans,s,target);
                solve(j+1 ,finalPath+"*"+tempPath, final-prev+ prev*num, prev*num,ans,s,target);
            }
        }

    }
    vector<string> addOperators(string num, int target) {
        vector<string>ans;
        solve(0,"",0,0,ans,num,target);
        return ans;
    }
};  