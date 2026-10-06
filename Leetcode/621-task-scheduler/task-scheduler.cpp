class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        for(auto x:tasks)mp[x]++;

        priority_queue<int>maxheap; // only freq

        for(auto x:mp)maxheap.push(x.second);

        //now heap h heap me freq h and we have n
        int c=0,count=0;
        while(!maxheap.empty()){
            vector<int>tempFreq;
            count = 0;
            for(int i=0;i<n+1 && (!maxheap.empty()) ; i++){
                int freq = maxheap.top();
                maxheap.pop();
                if (freq-1>0)tempFreq.push_back(freq - 1);
                count++;
            }
            for(auto x:tempFreq)maxheap.push(x);
            maxheap.empty()?c+=count:c+=n+1 ;
        }
        return c;
    }
};