class Solution {
public:
    
    int kadane(int idx, vector<int>& nums){
        int curr = nums[idx], maxi = nums[idx];
        
        for(int i = idx + 1; i < nums.size(); i++){
            curr = max(nums[i], curr + nums[i]);
            maxi = max(maxi, curr);
        }
        
        return maxi;
    }
    
    int maxSubarraySumCircular(vector<int>& nums) {
        int ans = kadane(0, nums), sum = 0;
        
        if(ans < 0)
            return ans;
        
        for(auto& i : nums)
            sum += i, i = -i;
        
        return max(ans, sum + kadane(0, nums));
    }
};