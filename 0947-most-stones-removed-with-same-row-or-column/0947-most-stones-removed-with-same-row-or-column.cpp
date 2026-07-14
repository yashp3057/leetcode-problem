class Disjointset {
public:
    vector<int> parents, size;

    Disjointset(int n) {
        parents.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++)
            parents[i] = i;
    }

    int finduparents(int node) {
        if (parents[node] == node)
            return node;

        return finduparents(parents[node]);
    }

    void unionbysize(int u, int v) {

        int up = finduparents(u);
        int vp = finduparents(v);

        if (up == vp)
            return;

        if (size[up] < size[vp]) {
            parents[up] = vp;
            size[vp] += size[up];
        } else {
            parents[vp] = up;
            size[up] += size[vp];
        }
    }
};



class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
int maxrow = 0, maxcol = 0;

for(auto it : stones)
{
    maxrow = max(maxrow, it[0]);
    maxcol = max(maxcol, it[1]);
}

Disjointset ds(maxrow + maxcol + 2);

unordered_map<int,int> mp;

for(auto it : stones)
{
    int row = it[0];
    int col = it[1] + maxrow + 1;

    ds.unionbysize(row, col);

    mp[row] = 1;
    mp[col] = 1;
}

int count = 0;

for(auto it : mp)
{
    if(ds.finduparents(it.first) == it.first)
        count++;
}

return stones.size() - count;

    }
};