class Solution {
public:
    
    vector<int> memo;
    
    int dp(int idx, vector<int>& cost){
        if(idx <= 1)
            return cost[idx];
        
        if(~memo[idx])
            return memo[idx];
        
        return memo[idx] = min(dp(idx - 1, cost), dp(idx - 2, cost)) + cost[idx];
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = int(cost.size());
        memo.assign(n + 5, -1);
        
        int ans = min(dp(--n, cost), dp(--n, cost));
        
        return ans;
    }
};