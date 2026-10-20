class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        priority_queue<int,vector<int>,greater<int>>minheap;
        for(auto x:hand)minheap.push(x);

        vector<int>temp;
        while(!minheap.empty()){
            int k = groupSize;
            int prev = -1;
            temp.clear();
            while(k){
                if(minheap.empty())return false;
                int top = minheap.top();
                if(prev == -1){
                    minheap.pop();
                    prev = top;
                    k--;
                    continue;
                }
                if(top-prev > 1)return false;
                else if(top -prev == 1){
                    minheap.pop();
                    k--;
                    prev = top;
                } 
                else{
                    temp.push_back(minheap.top());
                    minheap.pop();
                }
            }
            for(auto x:temp)minheap.push(x);
        }
        return true;
    }
};