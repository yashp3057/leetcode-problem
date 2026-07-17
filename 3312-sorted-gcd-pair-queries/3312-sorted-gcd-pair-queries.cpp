class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> freq(mx + 1, 0);
        for (int x : nums)
            freq[x]++;

        vector<long long> cntDiv(mx + 1, 0);

        // numbers divisible by d
        for (int d = 1; d <= mx; d++) {
            for (int j = d; j <= mx; j += d)
                cntDiv[d] += freq[j];
        }

        vector<long long> exact(mx + 1, 0);

        // inclusion-exclusion
        for (int d = mx; d >= 1; d--) {
            long long pairs = cntDiv[d] * (cntDiv[d] - 1) / 2;

            for (int j = d + d; j <= mx; j += d)
                pairs -= exact[j];

            exact[d] = pairs;
        }

        vector<pair<long long, int>> pref;

        long long sum = 0;

        for (int d = 1; d <= mx; d++) {
            if (exact[d]) {
                sum += exact[d];
                pref.push_back({sum, d});
            }
        }

        vector<int> ans;

        for (long long q : queries) {
            auto it = lower_bound(
                pref.begin(), pref.end(),
                make_pair(q + 1, 0),
                [](const pair<long long,int>& a,
                   const pair<long long,int>& b) {
                    return a.first < b.first;
                });

            ans.push_back(it->second);
        }

        return ans;
    }
};