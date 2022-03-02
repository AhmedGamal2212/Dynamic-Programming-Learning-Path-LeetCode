class Solution {
public:
    vector<int> getRow(int numRows) {
        vector<vector<int>> tri(numRows + 1);
        
        for(int i = 0; i < numRows + 1; i++){
            tri[i].resize(i + 1);
            for(int j = 0; j < tri[i].size(); j++){
                if(not j or j == i)
                    tri[i][j] = 1;
                else
                    tri[i][j] = tri[i - 1][j] + tri[i - 1][j - 1];
            }
        }
        return tri[numRows];
    }
};