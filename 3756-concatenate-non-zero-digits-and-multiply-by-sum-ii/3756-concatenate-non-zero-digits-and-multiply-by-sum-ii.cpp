class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        vector<int> pos;
        vector<int> digit;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '0') {
                pos.push_back(i);
                digit.push_back(s[i] - '0');
            }
        }

        int n = digit.size();

        vector<long long> prefSum(n + 1, 0);
        vector<long long> prefNum(n + 1, 0);
        vector<long long> pow10(n + 1, 1);

        for (int i = 0; i < n; i++) {
            prefSum[i + 1] = prefSum[i] + digit[i];
            prefNum[i + 1] = (prefNum[i] * 10 + digit[i]) % MOD;
            pow10[i + 1] = (pow10[i] * 10) % MOD;
        }

        vector<int> ans;

        for (auto &q : queries) {

            int L = q[0];
            int R = q[1];

            int l = lower_bound(pos.begin(), pos.end(), L) - pos.begin();
            int r = upper_bound(pos.begin(), pos.end(), R) - pos.begin() - 1;

            if (l > r) {
                ans.push_back(0);
                continue;
            }

            long long sum = prefSum[r + 1] - prefSum[l];

            int len = r - l + 1;

            long long number =
                (prefNum[r + 1] -
                 prefNum[l] * pow10[len] % MOD +
                 MOD) % MOD;

            ans.push_back((number * sum) % MOD);
        }

        return ans;
    }
};