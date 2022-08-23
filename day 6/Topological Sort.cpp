
void func(int v, vector<int> &ans, vector<vector<int>> &adj, vector<int> &indegree, vector<bool> &covered){
    ans.push_back(v);
    covered[v]=1;
    for(int x: adj[v]){
        indegree[x]--;
        if(indegree[x]==0)
            func(x, ans, adj, indegree, covered);
    }
}

vector<int> topologicalSort(vector<vector<int>> &edges, int n, int e)  {
    vector<vector<int>> adj(n);
    vector<int> indegree(n, 0);
    vector<bool> covered(n, 0);
    vector<int> ans;
    
    for(vector<int> x : edges){
        adj[x[0]].push_back(x[1]);
        indegree[x[1]]++;
    }
    for(int i=0; i<n; i++){
        if(!covered[i] && indegree[i]==0)
            func(i, ans, adj, indegree, covered);
    }
    return ans;
}