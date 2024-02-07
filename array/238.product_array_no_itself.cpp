#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:

   vector<int> productExceptSelf(vector<int> & nums)
   {
      int z_count = count(nums.begin(), nums.end(), 0);
      vector<int> res(nums.size());
      if (z_count > 1) { return res; }  // all zeros
      int prod = 1;
      for (int i = 0; i < nums.size(); i++)
      {
         if (nums[i] != 0)
         {
            prod *= nums[i];
         }
      }
      // read https://leetcode.com/problems/product-of-array-except-self/solutions/1342916/3-minute-read-mimicking-an-interview/?envType=study-plan-v2&envId=leetcode-75
      // 3 and 4. for (1) prefix+ suffix solution (2) no need to really consider 0
      for (int i = 0; i < nums.size(); i++)
      {
         res[i] = z_count == 1 ? 0 : prod / nums[i];
         res[i] = nums[i] == 0 ? prod : res[i];
      }
      return res;
   }
};