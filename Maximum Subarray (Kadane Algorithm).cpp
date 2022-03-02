class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int prev = -2e9, maxi = -1e9, curr = -1;
        
        for(auto& i : nums){
            if(prev == -2e9){
                prev = maxi = curr = i;
                continue;
            }
            curr = max(i, curr + i);
            maxi = max(maxi, curr);
        }
        
        return maxi;
    }
};