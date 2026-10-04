class KthLargest {
private:
    int k;
    priority_queue<int,vector<int>,greater<int>>minH;
public:
    KthLargest(int k, vector<int>& nums):k(k) {
        for(auto x:nums){
            minH.push(x);
            if(minH.size() > k)minH.pop();
        }
    }
    
    int add(int val) {  
        minH.push(val);
        if(minH.size() > k)minH.pop();

        return minH.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */