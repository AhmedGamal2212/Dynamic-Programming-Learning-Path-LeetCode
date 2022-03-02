class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum  = 0, size = int(prices.size());
        for(int i = 0; i < size - 1; i++){
            if(prices[i + 1] > prices[i]) 
                sum += prices[i + 1] - prices[i];
        }
        return sum;
    }
};