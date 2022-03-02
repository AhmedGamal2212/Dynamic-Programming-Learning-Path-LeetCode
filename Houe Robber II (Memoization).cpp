class Solution {
public:
    
    vector<vector<int>> memo;
    
    int dp(int idx, vector<int>& nums, bool taken){
        if(idx < 0 or (not idx and taken))
            return 0;
        
        if(~memo[idx][taken]){
            return memo[idx][taken];
        }
        
        return memo[idx][taken] = max(dp(idx - 1, nums, taken), 
                                     nums[idx] + dp(idx - 2, nums, taken));
    }
    
    int rob(vector<int>& nums) {
        int size = (int)nums.size();
        memo.assign(size + 5, vector<int>(2, -1));
        
        int ans = max(dp(size - 2, nums, false), nums[size - 1] + dp(size - 3, nums, true));
        
        
        return ans;
    }
};