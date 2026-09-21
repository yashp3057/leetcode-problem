class Solution {
public:
    vector<long long>resultArray(vector<int>& nums, int k) {

        int n = nums.size();

        // dp[r] = number of subarrays ending at previous index
        // whose product % k == r
        vector<long long> dp(k, 0);

        // answer[r] = total number of subarrays
        // whose product % k == r
        vector<long long> answer(k, 0);

        for (int i = 0; i < n; i++) {

            vector<long long> newdp(k, 0);

            // Start a new subarray with nums[i]
            int rem = nums[i] % k;
            newdp[rem]++;

            // Extend all previous subarrays
            for (int r = 0; r < k; r++) {

                if (dp[r] == 0)
                    continue;

                int newRem = (1LL * r * nums[i]) % k;

                newdp[newRem] += dp[r];
            }

            // Move to next index
            dp = newdp;

            // Add current subarrays to final answer
            for (int r = 0; r < k; r++) {
                answer[r] += dp[r];
            }
        }

        return answer;
    }
};