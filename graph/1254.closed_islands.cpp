#include<vector>
using namespace std;

// https://leetcode.com/problems/number-of-closed-islands/solutions/546884/c-easy-dfs-faster-than-99-81-memory-less-than-100/?orderBy=most_votes
// 1254. Number of Closed Islands
// https://leetcode.com/problems/number-of-closed-islands/
/*===========================================
1. The idea is to do dfs on land cells (0).
2. each dfs, once completed, yields an island that could be closed or bordered.
3. add an extra check in each dfs to see if the island is bordered `is_borderd`
4. if the island is not bordered, it is closed. In this case, increment the number of closed islands `n_islands`.

Time Complexity: O(mn)
Space Complexity: O(1); we modify the input grid in place
Note:
```return a&&b```
is not equivalent to
```
a
b
return a&&b
```
Because compilers can be optimized to not evaluate the `b` if `a` is false.
so if you do dfs in one line and && them together, it is possible that the later dfs-es
are not executed. 
=============================================*/
class Solution {
public:
    int n_islands = 0;
    void dfs(int x, int y, int m, int n, bool& is_bordered, vector<vector<int>>& grid){
        if (x < 0 || x >= m || y < 0 || y >= n){
            is_bordered = true;
            return;
        }
        if (grid[x][y] == 1){
            return;
        }
        vector<int> dir = {0, 1, 0, -1, 0};
        grid[x][y] = 1;
        for (int i=0; i < 4; i++){
            dfs(x + dir[i], y+dir[i+1], m, n, is_bordered, grid);
        }
    }
    int closedIsland(vector<vector<int>>& grid) {

        // find islands
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++){
            for (int j =0; j < n; j++){
                if (grid[i][j] == 0){
                    bool is_bordered = false;
                    dfs(i, j, m, n, is_bordered, grid);
                    if (!is_bordered) n_islands ++;
                }
            }
        }
        return n_islands;
    }
};