class Solution {
public:
     
    int minCostClimbingStairs(vector<int>& dp) {
        int n = int(dp.size());
        if(n == 1)
            return dp.back();
        if(n == 2)
            return min(dp.front(), dp.back());
        
        for(int i = 2; i < n; i++){
            dp[i] = min(dp[i - 1], dp[i - 2]) + dp[i];
        }
        
        return min(dp[--n], dp[--n]);
    }
};