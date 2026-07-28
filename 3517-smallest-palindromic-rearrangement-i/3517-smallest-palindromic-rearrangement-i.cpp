class Solution {
public:
    string smallestPalindrome(string s) {
        map<char, int> mpp;

        for (char c : s) {
            mpp[c]++;
        }

        string left = "";
        string right = "";
        string mid = "";

        for (auto it : mpp) {
            left.append(it.second / 2, it.first);

            if (it.second % 2 == 1) {
                mid += it.first;
            }
        }

        right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};