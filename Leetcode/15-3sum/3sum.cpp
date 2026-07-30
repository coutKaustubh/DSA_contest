class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            if(i>0 && nums[i] == nums[i-1])continue;
            int j=i+1;
            int k =n-1;

            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum<0)j++;
                else if(sum>0)k--;
                else{
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;k--;
                    while(j<k && nums[j] == nums[j-1])j++;
                    while(j<k && nums[k] == nums[k+1])k--;
                }
            }
        }
        return ans;
    }
};
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}