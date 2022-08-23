
void dfs(int v, vector<vector<int>> &adjTrans, vector<bool> &visited, vector<int> &ansj){
    visited[v]=1;
    for(int x: adjTrans[v]){
        if(!visited[x])
            dfs(x, adjTrans, visited, ansj);
    }
    ansj.push_back(v);
}

void topologicalSort(int v, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &sortedList){
    visited[v]=1;
    for(int x: adj[v]){
        if(!visited[x])
            topologicalSort(x, adj, visited, sortedList);
    }
    sortedList.push_back(v);
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(n);
    vector<vector<int>> adjTrans(n);
    vector<vector<int>> ans;
    for(auto x: edges){
        adj[x[0]].push_back(x[1]);
        adjTrans[x[1]].push_back(x[0]);
    }
    vector<int> sortedList;
    vector<bool> visited(n, 0);
    for(int i=0; i<n; i++){
        if(!visited[i]){
            topologicalSort(i, adj, visited, sortedList);
        }
    }
    for(int i=0; i<n; i++)
        visited[i]=0;
    int j=0;
    for(int i=n-1; i>=0; i--){
        if(!visited[sortedList[i]]){
            ans.push_back({});
            dfs(sortedList[i], adjTrans, visited, ans[j]);
            j++;
        }
    }
    return ans;
}