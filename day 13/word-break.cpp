class Solution
{
public:
    int wordBreak(string a, vector<string> &b) {
        vector<vector<int>> m(26);
        for(char x: a){
            if(!m[x-'a'].empty())
                continue;
            for(int i=0; i<b.size();i++){
                if(b[i][0]==x)
                    m[x-'a'].push_back(i);
            }
        }
        vector<bool> dp(a.size()+1,0);
        dp[a.size()]=1;
        for(int i=a.size()-1; i>=0; i--){
            for(int x: m[a[i]-'a']){
                bool f=1;
                for(int j=0; j<b[x].size() && f; j++){
                    if(j+i>=a.size() || a[j+i]!=b[x][j])
                        f=0;
                }
                dp[i]=f && dp[i+b[x].size()];
                if(dp[i])
                    break;
            }
        }
        return dp[0];
    }
};