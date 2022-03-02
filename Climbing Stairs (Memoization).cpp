class Solution {
public:
    vector<int> dp;
    
    int cntWays(int curr, int& n){
        if(curr >= n){
            return curr == n;
        }
        if(~dp[curr]) 
            return dp[curr];
        
        int cnt = 0;
        cnt += cntWays(curr + 1, n);
        cnt += cntWays(curr + 2, n);
        
        return dp[curr] = cnt;
    }
    
    int climbStairs(int n) {
        dp.assign(n + 5, -1);
        return cntWays(0, n);
    }
};