class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        for(int i=1; i<numRows; i++){
            vector<int> row(i+1);
            for(int j=0; j<i+1; j++){
                if(j==0 || j==i)
                    row[j]=1;
                else
                    row[j]=ans[i-1][j-1]+ans[i-1][j];
            }
            ans.push_back(row);
        }
        return ans;
    }
};