class Solution {
public:

    set<string> merge(set<string>& a, set<string>& b) {
        set<string> ans;

        for (string x : a) {
            for (string y : b) {
                ans.insert(x + y);
            }
        }

        return ans;
    }

    set<string> parse(string& s, int& i) {

        set<string> res;
        res.insert("");

        while (i < s.size() && s[i] != '}') {

            set<string> cur;

            // Case 1: opening brace
            if (s[i] == '{') {

                i++; // skip '{'

                cur = parse(s, i);

                i++; // skip '}'
            }

            // Case 2: lowercase letter
            else {

                cur.insert(string(1, s[i]));
                i++;
            }

            // Concatenate current result with cur
            res = merge(res, cur);

            // Case 3: comma
            if (i < s.size() && s[i] == ',') {

                i++;

                set<string> next = parse(s, i);

                for (string x : next)
                    res.insert(x);

                return res;
            }
        }

        return res;
    }

    vector<string> braceExpansionII(string expression) {

        int i = 0;

        set<string> ans = parse(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};