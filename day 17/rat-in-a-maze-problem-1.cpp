class Solution{
    public:
    
    void sol(int i,int j,vector<vector<int>> &m,int n,vector<string> &ans,string s){
        if(i==j && i==n-1){
            ans.push_back(s);
            return;
        }
        if(!m[i][j])
            return;
        m[i][j]=0;
        if(i>0)
            sol(i-1, j, m, n, ans, s+"U");
        if(i<n-1)
            sol(i+1, j, m, n, ans, s+"D");
        if(j>0)
            sol(i, j-1, m, n, ans, s+"L");
        if(j<n-1)
            sol(i, j+1, m, n, ans, s+"R");
        m[i][j]=1;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        if(m[n-1][n-1]==0)
            return {"-1"};
        vector<string> ans;
        sol(0,0,m,n, ans, "");
        return ans;
    }
};