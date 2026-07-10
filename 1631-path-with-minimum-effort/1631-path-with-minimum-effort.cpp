class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > q;

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        dist[0][0] = 0;
        q.push({0,{0,0}});

        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        while(!q.empty()){

            int diff = q.top().first;
            int row = q.top().second.first;
            int col = q.top().second.second;
            q.pop();

            if(row==n-1 && col==m-1)
                return diff;

            for(int i=0;i<4;i++){

                int nr = row + dr[i];
                int nc = col + dc[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m){

                    int effort = max(diff,
                                     abs(heights[nr][nc]-heights[row][col]));

                    if(effort < dist[nr][nc]){

                        dist[nr][nc] = effort;
                        q.push({effort,{nr,nc}});
                    }
                }
            }
        }

        return 0;
    }
};