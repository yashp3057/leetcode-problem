
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return abs(a) < abs(b);
        });

        int n = nums.size();
        long long mini = 0, maxi = 0;

        for (int i = 0; i < n / 2; i++) {
            mini += 1LL * nums[i] * nums[i];
        }

        for (int i = n / 2; i < n; i++) {
            maxi += 1LL * nums[i] * nums[i];
        }

        return maxi - mini;
    }
};
