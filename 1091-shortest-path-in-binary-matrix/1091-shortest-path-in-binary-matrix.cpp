class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n=grid.size();
    int m=grid[0].size();

      if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
      if(n==1) return 1;

    vector<vector<int>>dist(n,vector<int>(m,INT_MAX));

   queue<pair<int,pair<int,int>>>q;
   q.push({1,{0,0}});
 dist[0][0]=1;
   while(!q.empty()){
    
    auto top=q.front();
    q.pop();

   int occurence=top.first;
   int currow=top.second.first;
   int currcol=top.second.second;

   for(int i=-1; i<=1; i++){
   
   for(int j=-1; j<=1; j++){

   int nr=currow+i;
   int nc=currcol+j;

   if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==0 && occurence+1<dist[nr][nc]){
     if(nr==n-1 && nc==m-1) return occurence+1;
      dist[nr][nc]=occurence+1;
      q.push({occurence+1,{nr,nc}});
   }
      
   }


   }



   }

 

 return -1;

    }
};