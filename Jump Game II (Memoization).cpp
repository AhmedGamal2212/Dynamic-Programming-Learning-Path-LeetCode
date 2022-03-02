class Solution {
public:
    
    vector<int> memo;
    
    int dp(int idx, vector<int>& nums){
        if(idx >= nums.size() - 1)
            return 0;
        
        if(memo[idx] != INT_MAX)
            return memo[idx];
        
        
        int mini = 1e4;
        for(int i = 0; i < nums[idx]; i++){
            int curr_jump = nums[idx] - i;
            mini = min(mini, 1 + dp(idx + curr_jump, nums));
        }
        
        return memo[idx] = mini;
    }
    
    int jump(vector<int>& nums) {
        int size = int(nums.size());
        memo.assign(size + 5, INT_MAX);
        
        return dp(0, nums);
    }
};