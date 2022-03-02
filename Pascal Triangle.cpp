class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> tri(numRows);
        
        for(int i = 0; i < numRows; i++){
            tri[i].resize(i + 1);
            for(int j = 0; j < tri[i].size(); j++){
                if(not j or j == i)
                    tri[i][j] = 1;
                else
                    tri[i][j] = tri[i - 1][j] + tri[i - 1][j - 1];
            }
        }
        return tri;
    }
};