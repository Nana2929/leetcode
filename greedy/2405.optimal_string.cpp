#include<vector>
#include<string>
#include<set>
using namespace std;

/* ===============================================================

Optimal Partition of String
Link: https://leetcode.com/problems/optimal-partition-of-string/description/
2023.04.04 LeetCode Daily

This can be done with greedy.
The idea is to loop through the string s until we find a character that
is already in the current partition.
Then we start a new partition.

Solution, Time Complexity, Space Complexity
Sol1: Set Query, O(n) but depends on data structure design, O(n)
Sol2: Bitmasking, O(n), O(1)

==================================================================*/


class Solution {
public:
    int partitionString(string s) {

        set<char> seen; // use unordered_set for O(1) operations; C++ implements pure set as red-black tree which is O(logn)
        int n = 0;
        for (auto c:s){

            if (seen.count(c)){
                // break
                n ++;
                seen.clear();
                seen.insert(c);
            }
            else{
                seen.insert(c);
            }
        }
        if (!seen.empty()){
            n ++;
        }
        return n;
    }
    int partitionString_bit(string s) {
        int seen = 0;
        int result = 1;
        for (auto c:s){
            // << left shift operator
            // eg. if c == 'a', mask = 1
            // if c == 'b', mask = 10
            // if c == 'c', mask = 100
            // and so on, the idea is to make a mask that is set to 1 at the position of the current character
            // and off at all other positions
            int mask = (1 << (c - 'a'));
            // AND (&) try to sum each bit for the 2 operands
            // so if seen = 0001, mask = 0010, then seen & mask = 0000
            // -> meaning that the current character `b` is not in the current partition
            // if seen = 0001, mask = 0001, then seen & mask = 0001
            // -> meaning that the current character `a` is already in the current partition
            if (seen & mask){
                seen = 0;
                result ++;
            }
            // OR (^) set the bit at the position of the current character to 1
            // eg. if seen = 0000, mask = 0001, then seen = 0001
            // if seen = 0001, mask = 0010, then seen = 0011
            seen ^= mask;
        }
        return result;
    }

};