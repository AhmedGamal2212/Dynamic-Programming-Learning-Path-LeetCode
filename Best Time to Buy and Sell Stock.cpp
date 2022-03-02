class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minCost = INT_MAX, maxProfit = 0;
        
        for(auto& i : prices){
            if(i < minCost)
                minCost = i;
            else
                maxProfit = max(maxProfit, i - minCost);
        }
        return maxProfit;
    }
};