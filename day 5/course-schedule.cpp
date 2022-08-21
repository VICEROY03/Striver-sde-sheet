class Solution {
public:
    void dfs(int v, vector<vector<int>> &adj, vector<bool> &mark, vector<bool> &recStack, bool &ans){
        if(mark[v]){
            if(recStack[v])
                ans=0;
            return;
        }
        recStack[v]=1;
        mark[v]=1;
        for(auto x: adj[v])
            dfs(x, adj, mark, recStack, ans);
        recStack[v]=0;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(vector<int> x: prerequisites){
            if(x[0]==x[1])
                return 0;
            adj[x[0]].push_back(x[1]);
        }
        vector<bool> mark(numCourses, 0);
        vector<bool> recStack(numCourses, 0);
        bool ans=1;
        for(int i=0; i<numCourses; i++){            
            dfs(i, adj, mark, recStack, ans);
            if(!ans)
                return ans;
        }
        return ans;
    }
};