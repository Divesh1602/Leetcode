class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max = 0;
        int counter = 0;
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]!=0) {
                    countRecursiveAreaOfIsland(grid, i, j, counter);
                    if(max<counter) max = counter;
                    counter = 0;
                }
            }
        }
        return max;
    }
    void countRecursiveAreaOfIsland(vector<vector<int>>& grid, int r, int c, int& counter) {
        if (grid[r][c] != 0) {
            counter++;
            grid[r][c] = 0;
            if(r>=1) countRecursiveAreaOfIsland(grid, r-1, c, counter);
            if(c>=1) countRecursiveAreaOfIsland(grid, r, c-1, counter);
            if(r+1<grid.size()) countRecursiveAreaOfIsland(grid, r+1, c, counter);
            if(c+1<grid[0].size()) countRecursiveAreaOfIsland(grid, r, c+1, counter);
        }
    }
};