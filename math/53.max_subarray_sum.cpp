#include <iostream>
#include <stdio.h>
#include <vector>

/*
DP
Subproblem
Let the given array be A
x Wrong thought: DP[i:j] means the maximum subarray sum of the subarray A[i:j]
o Correct thought: DP[i] means the maximum subarray sum of the subarray A[0:i], AND A[i] must be included as the last element of the subarray

Recurrence
DP[i] = max(DP[i-1] + A[i], A[i]), which means for A[i], we check if it is better to start a new subarray or to extend the previous subarray

Final solution
max(DP[0], DP[1], ..., DP[n-1])



EXTRA
To find the subarray, we need to
- Record max(dp)
- find argmax(dp)
- The subarray's last index is argmax(dp)
- Starting from the last index and working backwards, we deduct the value of the current index from max(dp) until we reach 0
- The subarray's first index is the index of the first 0 we encounter

*/


using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int* dp = new int[nums.size()];
        int max_sum = nums[0];
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i-1]+nums[i], nums[i]);
            max_sum = max(max_sum, dp[i]);
        }
        return  max_sum;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << sol.maxSubArray(nums) << endl;
    return 0;
}