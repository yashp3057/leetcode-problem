class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, vector<int>> mpp;
        for (int i = 0; i < nums.size(); i++) {

            mpp[nums[i]].push_back(i);
        }

        for (auto x : mpp) {
            vector<int> v;
            for (auto y : x.second) {

                v.push_back(y);
            }
            if (v.size() > 1) {
                for (int i = 1; i < v.size(); i++) {
                    if (v[i] - v[i - 1] <= k) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};