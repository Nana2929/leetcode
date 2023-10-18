#include <iostream>
#include <stdio.h>
#include <vector>

/*
Description:
Given an integer array nums, find a
subarray that has the largest product, and return the product.
The test cases are generated so that the answer will fit in a 32-bit integer.


!!DP, but this one turns out quite different from max_subarray_sum!!


Thought:
- All elements are integer --> no need to consider floating point or multiply some x in which 0 < x < 1
- We need to consider negative numbers
- We need to consider 0
- Given dsacj's comment: [-1,4,-4,5,-2,-1,-1,-2,-3]
   - Our max-product subarray must include the first element or the last element (or both)  if there's no zero in the array
    - Suppose we have a subarray A[1:-1]'s max product, and would like to extend from both sides
    - first element > 0, last elemnt > 0: --> we include both
    - first element < 0, last elemnt > 0: --> we include last element
    - first element > 0, last elemnt < 0: --> we include first element
    - first element < 0, last elemnt < 0: --> we include both (negative * negative = positive)
- Therefore, our subproblem is
    - Let the given array be A
    - DP[i] means the maximum subarray product of the subarray A[0:i], and A[0] must be included as the last element of the subarray
    - However, we do not sure that if A[0] is really needed, there could be examples such as [0, 5, 8, -1, -4] in which we do not need A[0]
    - Therefore, we need to reverse the array and do the same thing again
    - This problem = max(DP, DP'), where DP' is the reversed DP
- What if there are zeroes in the array?
    - We can split the array into several smaller ones. That's to say, when the prefix product is 0, we start over and compute prefix profuct from the current element instead.

Python Version:
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        prefix, suffix, max_so_far = 0, 0, float('-inf')
        for i in range(len(nums)):
            prefix = (prefix or 1) * nums[i]
            suffix = (suffix or 1) * nums[~i]
            max_so_far = max(max_so_far, prefix, suffix)
        return max_so_far



https://leetcode.com/problems/maximum-product-subarray/solutions/183483/java-c-python-it-can-be-more-simple/

*/


using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int prefix_product = 0;
        int suffix_product = 0;
        int max_product = INT16_MIN;
        for (int i = 0; i < nums.size(); i++) {
            // if *_product is 0, we start over from the current element with 1 * nums[i]
            prefix_product = (prefix_product == 0 ? 1 : prefix_product) * nums[i];
            suffix_product = (suffix_product == 0 ? 1 : suffix_product) * nums[nums.size()-1-i];
            // c++ has max_element which works on a vector
            // for more than 2 elements' comparison, we need nested max()
            max_product = max(max_product, max(prefix_product, suffix_product));
        }

        return max_product;
    }
};

