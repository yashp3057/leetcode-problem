class Solution {
public:
    int mod = 1e9 + 7;

    int countPaths(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int,int>>> adj(n);

        for(auto it : roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > q;

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n,0);

        dist[0]=0;
        ways[0]=1;
        q.push({0,0});

        while(!q.empty()){

            long long dis=q.top().first;
            int node=q.top().second;
            q.pop();

          

            for(auto it:adj[node]){

                int adjacentnode=it.first;
                int weight=it.second;

                if(dis+weight<dist[adjacentnode]){

                    dist[adjacentnode]=dis+weight;
                    ways[adjacentnode]=ways[node];
                    q.push({dist[adjacentnode],adjacentnode});
                }

                else if(dis+weight==dist[adjacentnode]){

                    ways[adjacentnode]=(ways[adjacentnode]+ways[node])%mod;
                }
            }
        }

        return ways[n-1];
    }
};