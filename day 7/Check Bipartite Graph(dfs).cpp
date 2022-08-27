class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        stack<int> s;
        vector<bool> visited(n,0);
        vector<bool> set1(n,0);
        vector<bool> set2(n,0);
        vector<bool> sets[2]={set1,set2};
        
        for(int k=0; k<n; k++){
            if(visited[k])
                continue;
            int v,i;
            s.push(k);
            visited[k]=1;
            set1[k]=1;
            while(!s.empty()){
                v=s.top();
                if(sets[0][v])
                    i=0;
                else
                    i=1;
                s.pop();
                for(auto j: graph[v]){   
                    if(visited[j]){
                        if(sets[i][j])
                            return 0;
                        else
                            continue;
                    }
                    else{
                        s.push(j);
                        visited[j]=1;
                        sets[1-i][j]=1;
                    }
                }
            }
        }
        return 1;
    }
};