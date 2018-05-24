//https://leetcode.com/problems/number-of-islands-ii/description/
/*
A 2d grid map of m rows and n columns is initially filled with water.
We may perform an addLand operation which turns the water at position (row, col) into
a land. Given a list of positions to operate, count the number of islands after each addLand
operation. An island is surrounded by water and is formed by connecting adjacent lands horizontally
or vertically. You may assume all four edges of the grid are all surrounded by water.
*/

class Solution {
    vector<pair<int,int>> neis = {{0,1},{1,0},{0,-1},{-1,0}};
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> rst;
        if (m == 0 || n == 0)
            return rst;
        vector<vector<pair<int,int>>> roots(m,vector<pair<int,int>>(n, {-1,-1}));
        
        int count = 0;
        
        for (auto p : positions) {
            count++;
            roots[p.first][p.second] = {p.first, p.second};
            pair<int,int> cur = p;
            for (auto nei : neis) {
                int x = p.first + nei.first;
                int y = p.second + nei.second;
                if (x >= 0 && x < m && y >= 0 && y < n && roots[x][y].first != -1) { // valid
                    pair<int,int> next = findRoot(roots, make_pair(x,y));
                    if (next.first != cur.first || next.second != cur.second) {
                        roots[cur.first][cur.second] = next;
                        cur = next;
                        count--;
                    }
                }
            }
            rst.push_back(count);
        }
        return rst;
    }
    
    pair<int,int> findRoot(vector<vector<pair<int,int>>> &roots, pair<int,int> root) {
        while (roots[root.first][root.second].first != root.first
               || roots[root.first][root.second].second != root.second) {
            root = roots[root.first][root.second];
        }
        return root;
    }
};