
#include <limits>
#include <vector>

class Solution
{
public:

   double findMaxAverage(std::vector<int> & nums, int k)
   {

      // prefix sum
      for (int i = 1; i < nums.size(); i++)
      {
         nums[i] += nums[i - 1];
      }
      int sum = nums[k - 1];  // this means the sum of subarray ranging [0:k]
      for (int i = k; i < nums.size(); i++)
      {
         int curr_sum = nums[i] - nums[i - k];
         sum = std::max(sum, curr_sum);
      }
      return double(sum) / double(k);
   }
};