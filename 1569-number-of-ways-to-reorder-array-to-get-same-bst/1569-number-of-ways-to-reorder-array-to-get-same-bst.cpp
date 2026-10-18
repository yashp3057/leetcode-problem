class Solution {
public:
    const long long MOD = 1e9 + 7;
    long long C[1001][1001];

    long long solve(vector<int>& nums) {
        int n = nums.size();

        if (n <= 2) return 1;

        vector<int> left, right;

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[0])
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }

        long long a = solve(left);
        long long b = solve(right);

        return C[n - 1][left.size()] * a % MOD * b % MOD;
    }

    int numOfWays(vector<int>& nums) {
        for (int i = 0; i <= 1000; i++) {
            C[i][0] = 1;
            C[i][i] = 1;

            for (int j = 1; j < i; j++) {
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
            }
        }

        return (solve(nums) - 1 + MOD) % MOD;
    }
};