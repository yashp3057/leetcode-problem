class Solution {
public:

  void dfs(vector<vector<char>>&grid, vector<vector<int>>&vis,int n, int m,int row,int col){
int N[]={-1,0,1,0};
int c[]={0,1,0,-1};
     vis[row][col]=1;

    for(int i=0; i<4; i++){
     
     int nr=row+N[i];
     int nc=col+c[i];
     
if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]!=1 && grid[nr][nc]=='1'){
    dfs(grid,vis,n,m,nr,nc);
}
      

    }







  }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));

    int count=0;
    for(int i=0; i<n; i++){

    for(int j=0; j<m; j++){
  
  if(vis[i][j]==0 && grid[i][j]=='1'){
    count++;
    dfs(grid,vis,n,m,i,j);
  }



    }
    }


return count;

    }
};