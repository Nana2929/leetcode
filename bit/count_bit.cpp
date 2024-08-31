
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> NaiveCountBits(int n) {
        // O(nlgn), n being the input number
        // (lgn) for the __builtin_popcount() 
        vector<int> res(n+1, 0);
        for (int i = 0; i <= n; i++){
            res.push_back(__builtin_popcount(i));
        }
    }
    vector<int> DPCountBits(int n){
        // observe the pattern
        // dp[index] = dp[index-offset] +1
        // offset is the power of 2
        // see https://leetcode.com/problems/counting-bits/solutions/79557/how-we-handle-this-question-on-interview-thinking-process-dp-solution
        // O(n)
        vector<int>  dp (n+1, 0);
        int offset = 1;

        // offset goes like 0 for dp[0]
        //          *           *                              *
        // 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16
        // 1, 2, 2, 4, 4, 4, 4, 8, 8, 8,  8,  8,  8,  8,  8, 16
        // each offset repeats exactly "offset" times
        // we can double the offset every time the index is a power of 2 (when we meet *)
        for (int index=1; index <= n; index++){
            if (offset * 2 == index){
                offset *= 2;
            }
            dp[index] = dp[index-offset] + 1;
        }
        return dp;
};
};