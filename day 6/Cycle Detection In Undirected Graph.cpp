
bool dfs(int v, vector<vector<int>> &adj, vector<bool> &visited, int parent){
    visited[v]=1;
    for(int x: adj[v]){
        if(visited[x] && x!=parent)
            return 1;
        if(!visited[x] && dfs(x, adj, visited, v))
            return 1;
    }
    return 0;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<vector<int>> adj(n);
    for(vector<int> x : edges){
        adj[x[0]-1].push_back(x[1]-1);
        adj[x[1]-1].push_back(x[0]-1);
    }
    vector<bool> visited(n, 0);
    for(int i=0; i<n; i++){
        if(!visited[i] && dfs(i, adj, visited, -1))
            return "Yes";
    }
    return "No";
}
