class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        vector<string> v;

        int i = 0;

        while (i < s.size()) {
            string ans = "";

            // skip spaces
            while (i < s.size() && s[i] == ' ') {
                i++;
            }

            // create one word
            while (i < s.size() && s[i] != ' ') {
                ans += s[i];
                i++;
            }

            if (ans != "") {
                v.push_back(ans);
            }
        }

        if (pattern.size() != v.size())
            return false;

        unordered_map<char, string> mpp1;
        unordered_map<string, char> mpp2;

        for (int i = 0; i < pattern.size(); i++) {

            if (mpp1.find(pattern[i]) != mpp1.end()) {
                if (mpp1[pattern[i]] != v[i]) {
                    return false;
                }
            }

            if (mpp2.find(v[i]) != mpp2.end()) {
                if (mpp2[v[i]] != pattern[i]) {
                    return false;
                }
            }

            mpp1[pattern[i]] = v[i];
            mpp2[v[i]] = pattern[i];
        }

        return true;
    }
};