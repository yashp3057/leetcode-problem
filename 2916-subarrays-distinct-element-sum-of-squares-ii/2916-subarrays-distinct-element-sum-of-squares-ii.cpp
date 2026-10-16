
class Solution {
public:
    static const int MOD = 1e9 + 7;

    struct Node {
        long long sum = 0;
        long long sq = 0;
        long long lazy = 0;
    };

    vector<Node> seg;
    int n;

    void apply(int p, int l, int r, long long v) {
        long long len = r - l + 1;
        seg[p].sq = (seg[p].sq + 2 * v % MOD * seg[p].sum % MOD
                    + len % MOD * v % MOD * v % MOD) % MOD;
        seg[p].sum = (seg[p].sum + len * v) % MOD;
        seg[p].lazy = (seg[p].lazy + v) % MOD;
    }

    void push(int p, int l, int r) {
        if (seg[p].lazy == 0 || l == r) return;
        int m = (l + r) / 2;
        apply(p * 2, l, m, seg[p].lazy);
        apply(p * 2 + 1, m + 1, r, seg[p].lazy);
        seg[p].lazy = 0;
    }

    void update(int p, int l, int r, int ql, int qr, int v) {
        if (ql > r || qr < l) return;

        if (ql <= l && r <= qr) {
            apply(p, l, r, v);
            return;
        }

        push(p, l, r);
        int m = (l + r) / 2;
        update(p * 2, l, m, ql, qr, v);
        update(p * 2 + 1, m + 1, r, ql, qr, v);

        seg[p].sum = (seg[p * 2].sum + seg[p * 2 + 1].sum) % MOD;
        seg[p].sq = (seg[p * 2].sq + seg[p * 2 + 1].sq) % MOD;
    }

    int sumCounts(vector<int>& nums) {
        n = nums.size();
        seg.assign(4 * n + 5, Node());

        vector<int> last(100001, -1);
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int prev = last[nums[i]];

            update(1, 0, n - 1, prev + 1, i, 1);

            ans = (ans + seg[1].sq) % MOD;
            last[nums[i]] = i;
        }

        return ans;
    }
};
