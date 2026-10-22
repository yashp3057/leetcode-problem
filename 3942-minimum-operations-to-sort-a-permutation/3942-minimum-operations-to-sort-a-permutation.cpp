
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> target(n);

        for (int i = 0; i < n; i++) {
            target[i] = i;
        }

        int ans = INT_MAX;

        for (int j = 0; j < 2; j++) {
            int k = find(nums.begin(), nums.end(), 0) - nums.begin();
            bool flag = true;

            for (int i = 0; i < n; i++) {
                if (nums[(i + k) % n] != target[i]) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                if (j == 0) {
                    ans = min(ans, min(k, n - k + 2));
                } else {
                    ans = min(ans, 1 + min(k, n - k));
                }
            }

            reverse(nums.begin(), nums.end());
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
