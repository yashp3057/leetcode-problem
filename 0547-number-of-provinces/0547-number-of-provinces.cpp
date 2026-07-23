class Solution {
public:
    void dfs(vector<vector<int>>& list, vector<int>& vis, int node) {
        vis[node] = 1;

        for (auto it : list[node]) {
            if (!vis[it]) {
                dfs(list, vis, it);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<vector<int>> list(n);

        // Build adjacency list
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    list[i].push_back(j);
                }
            }
        }

        vector<int> vis(n, 0);
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                count++;
                dfs(list, vis, i);
            }
        }

        return count;
    }
};