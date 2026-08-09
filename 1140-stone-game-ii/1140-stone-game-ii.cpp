class Solution {
public:
    int n;
    vector<int> suffix;
    vector<vector<int>> dp;

    int helper(int i, int M) {

        
        if (i >= n)
            return 0;

    
        if (dp[i][M] != -1)
            return dp[i][M];

        int ans = 0;


        for (int X = 1; X <= 2 * M && i + X <= n; X++) {

            int nextM = max(M, X);

            int current = suffix[i] - helper(i + X, nextM);

            ans = max(ans, current);
        }

        return dp[i][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {

        n = piles.size();

       
        suffix.resize(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = piles[i] + suffix[i + 1];
        }

        dp.assign(n + 1, vector<int>(n + 1, -1));

        return helper(0, 1);
    }
};