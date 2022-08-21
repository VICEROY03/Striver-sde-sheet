public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        queue<int> q;
        q.push(0);
        vector<int> ans;
        vector<int> mark(V, 0);
        mark[0]=1;
        while(!q.empty()){
            int v = q.front();
            ans.push_back(v);
            q.pop();
            for(int x: adj[v]){
                if(!mark[x]){
                    q.push(x);
                    mark[x]=1;
                }
            }
        }
        return ans;
    }