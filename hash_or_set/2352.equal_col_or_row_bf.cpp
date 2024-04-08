
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

/*
https://leetcode.com/problems/equal-row-and-column-pairs
1. Brute Force*
2. Use hashing

Time: 145 ms (beats 19%)
Space: 26 MB (beats 96%)

Simply iterate over all pairs of rows and columns and check if they are equal.
*/
class Solution {
public:
    bool checkEqual(int i, int j, vector<vector<int>>& grid){
        size_t n = grid.size();
        for (int x =0;x<n; x++){
            if (grid[j][x] != grid[x][i]){
                return false;
            }
        }
        return true;
    }
    int equalPairs(vector<vector<int>>& grid) {
        // brute-force
        int ans = 0;
        size_t n = grid.size();
        for (int i = 0; i < n; i++){
            for (int j =0; j<n; j++){
                if (checkEqual(i,j, grid)){ans++;}
            }
        }
        return ans;
    }
};