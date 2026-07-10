class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int, int> mp;
        int idx = 0;

        for (int x : nums) {
            if (mp[x] < 2) {      
                nums[idx] = x;
                idx++;
                mp[x]++;
            }
        }

        return idx;
    }
};