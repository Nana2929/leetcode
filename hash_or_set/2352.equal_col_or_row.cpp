
#include <vector>
#include <unordered_map>
#include <iostream>
#include <map>
using namespace std;

/*
https://leetcode.com/problems/equal-row-and-column-pairs
1. Brute Force
2. Use hashing*

Time: 42 ms (beats 98%)
Space: 27.2 MB (beats 84%)
The idea is to hash each row and each column and then count the number of equal pairs of rows and columns.
Finally, choose col_counter or row_counter to iterate over, let's say col_counter,
for each key in col_counter, find the corresponding value in row_counter, and the multiplication of the two values is the number of equal pairs.

* How to hash an array:
Here's a basic idea of how you could implement such a hash function for an array of integers:
Choose a large prime number p to modulate the hash value and prevent overflow.
Choose a base b that is relatively prime to p and larger than the maximum value in your array.
Iterate through each element in the array, treating each element as a digit in a base b number, and compute the hash as you would for converting a number from base b to base 10.

* How to traverse an unordered_map:
https://stackoverflow.com/questions/50870951/iterating-over-unordered-map-c
for (auto& it: B) {
    cout << it.first;
}
*/
class ArrayHasher {
public:
    size_t operator()(int index, int col_or_row, const vector<vector<int>>& grid) const {
        // Hashing an array (by ChatGPT)
        // Hashing a string: https://stackoverflow.com/questions/8029121/how-to-hash-stdstring
        const size_t p = 1000000007; // Large prime number
        const size_t b = 100003; // Base value, relatively prime to p and greater to any element inside array
        // the range of the elements in the array is [0, 10^5]
        size_t hash = 0;
        for (int i =0;i<grid.size();i++) {
            int num = col_or_row==1? grid[index][i]: grid[i][index]; // col_or_row=1 represents col
            hash = (hash * b + num) % p;
        }
        return hash;
    }
};

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        ArrayHasher hasher;
        unordered_map<size_t,int> row_counter;
        unordered_map<size_t,int> col_counter;
         // https://stackoverflow.com/questions/41103505/how-to-use-stdvector-as-the-type-of-key-for-an-stdunordered-map-in-c
        // If the value inside is readily accessible as a whole, Write a hash function and pass it into unorderd_map's 3rd arg
        for (int i = 0;i< grid.size();i++){
            size_t hashed = hasher(i,0,grid);
            row_counter[hashed]++;
        }
        for (int i = 0;i< grid.size();i++){
            size_t hashed = hasher(i,1, grid);
            col_counter[hashed]++;
        }
        int ans = 0;
        for (auto& it: col_counter){
            size_t key=it.first;
            ans+=it.second * row_counter[key]; // row_counter[key] returns 0 if not found
        }
        return ans;
    }
};

// 看了 Solutions 發現，C++ map 內有為 vector<int> implement hash
class Solution2 {
public:
    int equalPairs(vector<vector<int>>& grid) {
        // Unordered map requires availability of hash function for the key. Such function does not exist for std::vector in standard implementation.
        // You could use std::map, though - it requires comparison operator, which exists for vector.
        // If you really must use vector as a key to hash map (which seems dubious), you should implement hashing function yourself.

        map<vector<int>, int> counter;
        int row = grid.size(), col = grid[0].size(), ans = 0;
        for (vector<int> row : grid) {
            counter[row] += 1;
        }
        for (int i = 0; i < row; i++) {
            vector<int> column_list = {};
            for (int j = 0; j < col; j++) {
                column_list.push_back(grid[j][i]);
            }
            ans += counter[column_list];
        }
        return ans;
    }
};