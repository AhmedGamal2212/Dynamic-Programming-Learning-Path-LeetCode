class Solution {
public:
    
    int n;
    vector < int > a, dp;   
    int maxAmount(int idx){
        if(idx >= n) 
            return 0;
        
        if(dp[idx] != -1) return dp[idx];
        
        int p1 = maxAmount(idx + 1);
        int p2 = maxAmount(idx + 2) + a[idx];
        
        return dp[idx] = max(p1, p2 );
            
            
            
    }
    
    int rob(vector<int>& nums) {
        n = int(nums.size());
        dp.assign(n + 1, -1);
        a = nums;
        return maxAmount(0);
    }
};