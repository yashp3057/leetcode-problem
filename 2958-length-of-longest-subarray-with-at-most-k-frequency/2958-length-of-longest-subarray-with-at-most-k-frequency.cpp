class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        unordered_map<int, int> mpp;
        int maxlen = 0;
        while (r < n) {

            mpp[nums[r]]++;
            if(mpp[nums[r]] <= k) maxlen = max(maxlen, r - l + 1);
            else{
            while (mpp[nums[r]] > k) {
                
                mpp[nums[l]]--;
                
                if (mpp[nums[l] == 0]) {
                    mpp.erase(nums[l]);
                }
                l++;
                maxlen = max(maxlen, r - l + 1);
            }
            }
            //maxlen = max(maxlen, r - l + 1);

            r++;
        }

        return maxlen;
    }
};