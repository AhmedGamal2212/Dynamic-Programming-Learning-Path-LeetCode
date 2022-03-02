class Solution {
public:
    
    vector<int> memo;
    
    bool dp(int idx, vector<int>& nums){
        if(idx >= nums.size() - 1)
            return true;
        
        if(~memo[idx])
            return memo[idx];
        
        bool nxt = false;
        
        for(int i = 0; i < nums[idx]; i++){
            nxt |= dp(idx + nums[idx] - i, nums);
            if(nxt)
                break;
        }
        return memo[idx] = nxt;
    }
    
    bool canJump(vector<int>& nums) {
        int size = (int)nums.size();
        memo.assign(size + 5, -1);
        
        return dp(0, nums);
    }
};