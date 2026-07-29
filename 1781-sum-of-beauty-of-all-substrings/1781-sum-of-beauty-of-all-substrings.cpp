class Solution {
public:
    int beautySum(string s) {
        int beauty = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            unordered_map<char, int> mpp;

            for (int j = i; j < n; j++) {

                mpp[s[j]]++;

                int maxi = 0;
                int mini = INT_MAX;

                for (auto it : mpp) {
                    maxi = max(maxi, it.second);
                    mini = min(mini, it.second);
                }

                beauty += (maxi - mini);
            }
        }

        return beauty;
    }
};