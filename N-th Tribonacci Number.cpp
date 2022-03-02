class Solution {
public:
    
    long long memo[40];
    
    long long solve(int n){
        if(n <= 2)
            return min(n, 1);
        if(~memo[n])
            return memo[n];
        return memo[n] = solve(n - 1) + solve(n - 2) + solve(n - 3);
    }
    
    int tribonacci(int n) {
        memset(memo, -1, sizeof memo);
        return solve(n);
    }
};