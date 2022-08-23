
bool dfs(int v, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &recStack){
        if(visited[v])
            return recStack[v];
        recStack[v]=1;
        visited[v]=1;
        for(auto x: adj[v])
            if(dfs(x, adj, visited, recStack))
                return 1;
        recStack[v]=0;
    return 0;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    vector<vector<int>> adj(n);
    for(pair<int, int> x: edges)
        adj[x.first-1].push_back(x.second-1);
    vector<bool> visited(n, 0);
    vector<bool> recStack(n, 0);
    for(int i=0; i<n; i++){            
        if(!visited[i] && dfs(i, adj, visited, recStack))
            return 1;
    }
    return 0;
}