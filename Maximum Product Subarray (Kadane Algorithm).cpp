class Solution {
public:
    
    #define all(v) v.begin(), v.end()
    
    int maxProduct(vector<int>& nums) {
        int currRight = 1, maxiRight = -2e9,
        currLeft = 1, maxiLeft = -2e9;
        
        for(int i = 0; i < nums.size(); i++){
            currRight *= nums[i];
            maxiRight = max(maxiRight, currRight);
            
            if(not currRight)
                currRight = 1;
            
            currLeft *= nums[nums.size() - i - 1];
            maxiLeft = max(maxiLeft, currLeft);
            
            if(not currLeft)
                currLeft = 1;
        }
        
        return max(maxiRight, maxiLeft);
    }
};