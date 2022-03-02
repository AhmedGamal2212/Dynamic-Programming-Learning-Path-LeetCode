class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;
        
        int a = 0, b = 1, temp;
        for(int i = 0; i < n; i++){
            temp = a;
            a = a + b;
            b = temp;
        }
        return a;
    }
};