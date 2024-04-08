#include <vector>
using namespace std;
/*
Time Complexity
amortized: O(nlogn)
worst-case: O(n^2) (when the pivot is the smallest or largest element)
*/
class Solution
{
public:

   vector<int> sortArray(vector<int> & nums)
   {
      QuickSort(nums, 0, nums.size() - 1);
      return nums;
   }

   
   void QuickSort(vector<int> & arr, int front, int end)
   {
      // Divide and Conquer
      if (front < end)
      {
         int pivot = Partition(arr, front, end);
         QuickSort(arr, front, pivot - 1);
         QuickSort(arr, pivot + 1, end);
      }
   }
   void swap(vector<int> & arr, int i, int j)
   {
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
   }
   int Partition(vector<int> & arr, int front, int end)
   {
      int pivot = arr[front];
      int i = front;
      for (int j = front + 1; j <= end; j++)
      {
         if (arr[j] < pivot)
         {
            i++;
            swap(arr, i, j);
         }
      }
      swap(arr, i, front);
      return i;
   }
};