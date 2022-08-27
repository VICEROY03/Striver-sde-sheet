int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    const int inf=1000000000;
    int arr[n+1][n+1][n+1];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j)
                arr[0][i][j]=0;
            else
                arr[0][i][j]=inf;
        }
    }
    for(auto x: edges){
        arr[0][x[0]][x[1]]=x[2];
    }
    
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(i==k || j==k || i==j)
                    arr[k][i][j]=arr[k-1][i][j];
                else if(arr[k-1][i][j]<arr[k-1][i][k]+arr[k-1][k][j])
                    arr[k][i][j]=arr[k-1][i][j];
                else if(arr[k-1][i][k]!=inf && arr[k-1][k][j]!=inf)
                    arr[k][i][j]=arr[k-1][i][k]+arr[k-1][k][j];
                else
                    arr[k][i][j]=arr[k-1][i][j];
            }
        }
    }
    return arr[n][src][dest];
}