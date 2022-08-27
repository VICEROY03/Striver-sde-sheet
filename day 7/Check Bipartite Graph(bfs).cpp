#include <queue>
bool isGraphBirpatite(vector<vector<int>> &edges) {
    int n=edges.size();
    queue<int> q;
    int parent=0;
    vector<bool> visited(n,0);
    vector<bool> set1(n,0);
    vector<bool> set2(n,0);
    vector<bool> sets[2]={set1,set2};
    q.push(0);
    visited[0]=1;
    set1[0]=1;
    int v,i;
    while(!q.empty()){
        v=q.front();
        if(sets[0][v])
            i=0;
        else
            i=1;
        q.pop();
        for(int j=0; j<n; j++){
            if(edges[v][j]){
                if(visited[j]){
                    if(sets[i][j])
                        return 0;
                }
                else{
                    q.push(j);
                    visited[j]=1;
                    sets[1-i][j]=1;
                }
            }
        }
    }
    return 1;
}