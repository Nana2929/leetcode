#include <iostream>
#include <vector>
using namespace std;

#define OFFSET 5e+4
class Solution
{
public:

   vector<int> sortArray(vector<int> & nums)
   {
      // use counting sort
      vector<int> counter(OFFSET * 2 + 1);
      for (auto num : nums)
      {
         counter[num + OFFSET]++;
      }
      vector<int> output(nums.size());
      // stable sort: starting from end
      for (int j = nums.size() - 1; j >= 0; j--)
      {
         int x = nums[j];
         output[--counter[x + OFFSET]] = x;
      }
      return output;
   }
};

int main()
{
   // test cases
   vector<int> nums = {5, 2, 3, 1, 2, 14};
   Solution sol;
   sol.sortArray(nums);
   for (auto x : nums)
   {
      cout << x << " ";
   }
   return 0;
}