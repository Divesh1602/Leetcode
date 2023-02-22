class Solution {
public:
    bool isSafe(vector<string> board,int row,int col,int n){
        int dupRow=row;
        int dupCol=col;
        
        while(row>=0 && col>=0){
            if(board[row][col]=='Q')
                return false;
            row--;
            col--;
        }
        col=dupCol;
        row=dupRow;
        while(col>=0){
            if(board[row][col]=='Q')
                return false;
            col--;
        }
        col=dupCol;
        row=dupRow;
        while(row<n && col>=0){
            if(board[row][col]=='Q')
                return false;
            col--;
            row++;
        }
        return true;
    }
    
    
    void helper(vector<vector<string>>& ans,vector<string> board,int n,int col){
        if(col==n){
            ans.push_back(board);
            return;
        }
        
        for(int row=0;row<n;row++){
            if(isSafe(board,row,col,n)){
                board[row][col]='Q';
                helper(ans,board,n,col+1);
                board[row][col]='.';
            }
        }
        return;
        
    }
    
    int totalNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        helper(ans,board,n,0);
        return ans.size();
        
    }
};