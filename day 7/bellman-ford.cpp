int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    int inf=1e9;
    vector<int> dist(n+1, inf);
    dist[src]=0;
    n--;
    while(n--){
        for(auto edge: edges){
            if(dist[edge[0]]!=inf && dist[edge[1]]>dist[edge[0]]+edge[2])
                dist[edge[1]]=dist[edge[0]]+edge[2];
        }
    }
    return dist[dest];
}