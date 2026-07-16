class Solution {
public:

int findgcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

    long long gcdSum(vector<int>& nums) {

        int n = nums.size();

        vector<int> maxi(n);
        maxi[0] = nums[0];

        for (int i = 1; i < n; i++) {
            maxi[i] = max(nums[i], maxi[i - 1]);
        }

        vector<int> gcd(n);

        for (int i = 0; i < n; i++) {
            gcd[i] = findgcd(nums[i], maxi[i]);
        }

        sort(gcd.begin(), gcd.end());

        long long sum = 0;

        int i = 0;
        int j = n - 1;

        while (i < j) {
            sum += findgcd(gcd[i], gcd[j]);
            i++;
            j--;
        }

        return sum;
    }
};