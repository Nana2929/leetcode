#include <algorithm>
#include <vector>

class Solution
{
public:

   /*
   time complexity: O(nlgn) + O(n)
   */
   int maxOperations(std::vector<int> & nums, int k)
   {
      // sort, 2-pointer
      std::sort(nums.begin(), nums.end());
      int i = 0;
      int j = nums.size() - 1;
      int maxop = 0;
      while (i < j)
      {
         if (nums[i] + nums[j] == k)
         {
            maxop++;
            i++;
            j--;
         }
         else if (nums[i] + nums[j] < k) { i++; }
         else { j--; }
      }
      return maxop;
   }
};