class Solution {
public:
    int subBox(int i, int j){
        if(i<3 && j<3)
            return 0;
        else if(i<3 && j<6)
            return 1;
        else if(i<3 && j<9)
            return 2;
        else if(i<6 && j<3)
            return 3;
        else if(i<6 && j<6)
            return 4;
        else if(i<6 && j<9)
            return 5;
        else if(i<9 && j<3)
            return 6;
        else if(i<9 && j<6)
            return 7;
        else if(i<9 && j<9)
            return 8;
        return -1;
    }
    void sol(vector<vector<bool>> &row, vector<vector<bool>> &col, vector<vector<bool>> &sqr, vector<vector<int>> &mt, int i, vector<vector<char>>& board, bool& ans){
        if(i==mt.size()){
            ans=1;
            return;
        }
        int r=mt[i][0], c=mt[i][1], k = subBox(r, c);;
        for(int j=1; j<=9; j++){
            if(!row[r][j] && !col[c][j] && !sqr[k][j]){
                row[r][j]=1;
                col[c][j]=1;
                sqr[k][j]=1;
                board[r][c]='0'+j;
                sol(row,col,sqr,mt,i+1,board,ans);
                if(ans)
                    return;
                row[r][j]=0;
                col[c][j]=0;
                sqr[k][j]=0;
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9, vector<bool>(10,0));
        vector<vector<bool>> col(9, vector<bool>(10,0));
        vector<vector<bool>> sqr(9, vector<bool>(10,0));
        vector<vector<int>> mt;
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                char c=board[i][j];
                if(c=='.'){
                    mt.push_back({i,j});
                    continue;
                }                    
                sqr[subBox(i,j)][c-'0']=1;
                row[i][c-'0']=1;
                col[j][c-'0']=1;
            }
        }
        bool ans=0;
        sol(row, col, sqr, mt, 0, board, ans);
    }
};