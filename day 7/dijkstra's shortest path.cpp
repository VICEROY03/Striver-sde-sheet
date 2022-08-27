#include <bits/stdc++.h>
vector<int> dijkstra(vector<vector<int>> &vec, int n, int edges, int src) {
    int INF=2147483647;
    vector<vector<pair<int,int>>> adj(n);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(n);
    for(int i=0; i<n; i++)
        dist[i]=INF;
    dist[src]=0;
    pq.push({dist[src],src});

    for(auto edge: vec){
        adj[edge[0]].push_back({edge[1], edge[2]});
        adj[edge[1]].push_back({edge[0], edge[2]});
    }
    int u;
    while(!pq.empty()){
        u=pq.top().second;
        pq.pop();
        for(pair<int,int> p: adj[u]){
            int v=p.first, c=p.second;
            if(dist[v]>dist[u]+c){
                dist[v]=dist[u]+c;
                pq.push({dist[v],v});
            }
        }
    }
    vector<int> ans;
    for(int i=0; i<n; i++)
        ans.push_back(dist[i]);
    return ans;
}
