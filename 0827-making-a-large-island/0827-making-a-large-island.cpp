class Disjointset {
public:
    vector<int> parents, size;

    Disjointset(int n) {
        parents.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++)
            parents[i] = i;
    }

    int finduparents(int node) {
        if (parents[node] == node)
            return node;

        return finduparents(parents[node]);
    }

    void unionbysize(int u, int v) {

        int up = finduparents(u);
        int vp = finduparents(v);

        if (up == vp)
            return;

        if (size[up] < size[vp]) {
            parents[up] = vp;
            size[vp] += size[up];
        } else {
            parents[vp] = up;
            size[up] += size[vp];
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        Disjointset ds(n * m);
        // first we connected compnentes bes=cause end of the problem we have
        // need ultimate components size
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0)
                    continue;

                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, 1, 0, -1};
                for (int k = 0; k < 4; k++) {
                    int nr = i + dr[k];
                    int nc = j + dc[k];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                        if (grid[nr][nc] == 1) {
                            int nodeno = i * m + j;
                            int adjacentnode = nr * m + nc;
                            if (ds.finduparents(nodeno) !=
                                ds.finduparents(adjacentnode)) {
                                ds.unionbysize(nodeno, adjacentnode);
                            }
                        }
                    }
                }
            }
        }

        // now  above we connected graph compnonees and now we check when we
        // zero  put and get maximum answer so this time grid==0 we check
        // adjancent and put data into the set data structure
   
    int maxi=0;
     for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
         
         if(grid[i][j]==1) continue;
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, 1, 0, -1};
                 set<int>st;
                for(int k=0; k<4; k++){
                    int nr=i+dr[k];
                    int nc=j+dc[k];
                   
                   if(nr>=0 && nr<n && nc>=0 && nc<m){
                    
                    if(grid[nr][nc]==1){
                      st.insert(ds.finduparents(nr*m+nc));
                    }


                   }


                }
            int totalsize=0;
            for(auto it:st){
               totalsize+=ds.size[it];
            }   
            maxi=max(maxi,totalsize+1); 

        }
     }
     for(int i = 0; i < n * m; i++) {
    maxi = max(maxi, ds.size[ds.finduparents(i)]);
}

return maxi;
    }
};