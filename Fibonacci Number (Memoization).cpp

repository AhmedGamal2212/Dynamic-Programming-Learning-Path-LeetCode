class Solution {
public:
    long long memo[35];
    
    int solve(int n){
        if(n <= 1)
            return n;
        if(~memo[n])
            return memo[n];
        return memo[n] = fib(n - 1) + fib(n - 2);

    }
    
    int fib(int n) {
        memset(memo, -1, sizeof memo);
        return solve(n);    
    }
};