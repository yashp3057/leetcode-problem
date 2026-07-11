class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        // Distance matrix
        vector<vector<int>> dis(n, vector<int>(n, INT_MAX));

        // Distance from a city to itself is 0
        for (int i = 0; i < n; i++) {
            dis[i][i] = 0;
        }

        // Fill initial distances using edges
        for (auto &it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            dis[u][v] = wt;
            dis[v][u] = wt;
        }

        // Floyd-Warshall Algorithm
        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {

                    if (dis[i][via] == INT_MAX || dis[via][j] == INT_MAX)
                        continue;

                    dis[i][j] = min(dis[i][j], dis[i][via] + dis[via][j]);
                }
            }
        }

        int city = -1;
        int mini = INT_MAX;

        // Count reachable cities
        for (int i = 0; i < n; i++) {

            int count = 0;

            for (int j = 0; j < n; j++) {
                if (dis[i][j] <= distanceThreshold)
                    count++;
            }

            // If tie, choose larger city number
            if (count <= mini) {
                mini = count;
                city = i;
            }
        }

        return city;
    }
};