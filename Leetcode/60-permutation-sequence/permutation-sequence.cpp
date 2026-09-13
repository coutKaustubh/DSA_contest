class Solution {
public:
    int fact(int n){
        if(n==1 || n==0)return 1;
        return n*fact(n-1);
    }

    string getPermutation(int n, int k) {
        int num = n;
        string ans = "";
        vector<int> available;

        for(int i=1;i<=n;i++){
            available.push_back(i);
        }

        while(num){
            int totalBlocks = fact(num-1);
            int block = (k-1)/totalBlocks;
            ans += to_string(available[block]);
            available.erase(available.begin()+block);
            k = (k-1)%totalBlocks + 1;
            num--;
        }

        return ans;
    }
};