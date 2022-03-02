class Solution {
public:
    
    vector<int> memo, cnt;
    
    int dp(int idx, vector<int>& nums){
        if(~memo[idx])
            return memo[idx];
        
        if(not idx)
            return nums.front() * cnt[nums.front()];
        
        if(idx == 1){
            if(nums[idx] - 1 == nums[idx - 1]){
                return max(nums[idx] * cnt[nums[idx]], 
                           nums[idx - 1] * cnt[nums[idx - 1]]);
            }else{
                return nums[idx] * cnt[nums[idx]] + nums[idx - 1] * cnt[nums[idx - 1]];
            }
        }
        
        if(nums[idx] - 1 == nums[idx - 1])
            memo[idx] = max(dp(idx - 1, nums), 
                                  dp(idx - 2, nums) + nums[idx] * cnt[nums[idx]]);
        else 
            memo[idx] = cnt[nums[idx]] * nums[idx] + dp(idx - 1, nums);
        
        return memo[idx];
    }
 
    
    int deleteAndEarn(vector<int>& nums) {
        int size = (int)nums.size();
        
        memo.assign(size + 5, -1), cnt.resize(3e4);
        
        for(auto& i : nums){
            cnt[i]++;
        }
        
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        
        size = int(nums.size());
        int ans = dp(size - 1, nums);
        
        
        return ans;
    }
};