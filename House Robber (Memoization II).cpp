class Solution {
public:
    
    vector<int> memo;
    int n;
    
    int dp(int idx, vector<int>& nums){
        if(not idx) 
            return nums.front();
        if(idx == 1)
            return max(nums.front(), nums[1]);
        
        if(~memo[idx])
            return memo[idx];
        
        return memo[idx] = max(dp(idx - 2, nums) + nums[idx], dp(idx - 1, nums));
    }
    
    int rob(vector<int>& nums) {
        memo.assign(405, -1), n = nums.size();
        return dp(n - 1, nums);
    }
};