class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<pair<string, string>> v;

        // Store: {sorted string, original string}
        for (int i = 0; i < strs.size(); i++) {
            string s = strs[i];
            string temp = s;

            sort(temp.begin(), temp.end());

            v.push_back({temp, s});
        }

        // Sort according to sorted string
        sort(v.begin(), v.end());

        vector<vector<string>> result;

        int i = 0;

        while (i < v.size()) {
            vector<string> ans;

            int j = i;

            while (j < v.size() && v[j].first == v[i].first) {
                ans.push_back(v[j].second);
                j++;
            }

            result.push_back(ans);
            i = j;
        }

        return result;
    }
};