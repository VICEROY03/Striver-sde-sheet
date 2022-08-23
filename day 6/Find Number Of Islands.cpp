
int row[8]={0,0,-1,-1,-1,1,1,1};
int col[8]={-1,1,-1,0,1,-1,0,1};

void dfs(int n, int m, int x, int y, bool** map, int** arr){
    map[x][y]=1;
    for(int i=0; i<8; i++){
        if(row[i]+x<n && row[i]+x>=0 && col[i]+y<m && col[i]+y>=0 && arr[row[i]+x][col[i]+y] && !map[row[i]+x][col[i]+y])
            dfs(n, m, row[i]+x, col[i]+y, map, arr);
    }
}
int getTotalIslands(int** arr, int n, int m)
{
    int ans=0;
    bool** map= new bool*[n];
    for(int i=0; i<n; i++){
        map[i] = new bool[m];
        for(int j=0; j<m; j++)
            map[i][j]=0;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] && !map[i][j]){
                dfs(n, m, i, j, map, arr);
                ans++;
            }
        }
    }
    return ans;
}
