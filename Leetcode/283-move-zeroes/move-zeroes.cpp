class Solution {
public:
    void moveZeroes(vector<int>& v) {
        int c = count(v.begin(),v.end(),0);
        v.erase(remove(v.begin(), v.end(), 0), v.end());
        for(int i=0;i<c;i++)v.push_back(0);
    }
};