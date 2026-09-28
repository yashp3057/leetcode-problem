class Solution {
public:
    int maxDepth(string s) {

        stack<int> st;
        int maxi = 0;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {
                st.push(s[i]);
                maxi = max(maxi, (int)st.size());
            }

            else if (s[i] == ')' && !st.empty() && st.top() == '(') {
                st.pop();
            }
        }

        return maxi;
    }
};