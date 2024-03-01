/*in-place Merge Sort
time complexity
O(n * logn)
Space Complexity
O(n)
https://leetcode.com/problems/sort-an-array/solutions/1401412/c-clean-code-solution-fastest-all-15-sorting-methods-detailed
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:

   vector<int> sortArray(vector<int> & nums)
   {
      MergeSort(nums, 0, nums.size() - 1);
      return nums;
   }
   void MergeSort(vector<int> & nums, int low, int high)
   {
      if (low < high)
      {
         int mid = low + (high - low) / 2;
         MergeSort(nums, low, mid);
         MergeSort(nums, mid + 1, high);
         Merge(nums, low, mid, high);
      }
   }
   void Merge(vector<int> & nums, int low, int mid, int high)
   {
      // extra space used for assistance but is generally in-place
      vector<int> left(nums.begin() + low, nums.begin() + mid + 1);
      vector<int> right(nums.begin() + mid + 1, nums.begin() + high + 1);
      int i = 0, j = 0, k = low;
      while (i < left.size() && j < right.size())
      {
         if (left[i] < right[j]) { nums[k++] = left[i++]; }
         else { nums[k++] = right[j++]; }
      }
      // copying remaining
      while (i < left.size())
      {
         nums[k++] = left[i++];
      }
      while (j < right.size())
      {
         nums[k++] = right[j++];
      }
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