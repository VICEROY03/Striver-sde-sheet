 public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int v, vector<int> adj[], vector<int> &mark, vector<int> &ans){
        if(mark[v]) return;
        mark[v]=1;
        ans.push_back(v);
        for(auto x: adj[v])
            dfs(x, adj, mark, ans);
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> mark(V, 0);
        vector<int> ans;
        dfs(0, adj, mark, ans);
        return ans;
    }