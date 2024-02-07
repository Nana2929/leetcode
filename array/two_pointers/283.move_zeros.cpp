#include <vector>
using namespace std;

class Solution
{
public:

   void moveZeroes(vector<int> & nums)
   {
      // super cool solution thanks to @phelt
      /*
      This algorithm works like this:
      for [5, 8, 0, 4, 3, 0, 2] array
      (): the seen nums[i]
      (5) i=0, next=0; swapping itself = no swap, next = 1 | [5, 8, 0, 4, 3, 0, 2]
      (8) i=1, next=1; swapping itself = no swap, next = 2 | [5, 8, 0, 4, 3, 0, 2]
      (0) i=2, next=2; no swapping since condition not satsfied  | [5, 8, 0, 4, 3, 0, 2]
      (4) i=3, next=2: swapping nums[3] and nums[2], next = 3 | [5, 8, 4, 0, 3, 0, 2]
      (3) i=4, next=3: swapping nums[4] and nums[3], next = 4 | [5, 8, 4, 3, 0, 0, 2]
      (0) i=5, next=4: no swapping since condition not satsfied  | [5, 8, 4, 3, 0, 0, 2]
      (2) i=6, next=4: swapping nums[6] and nums[4], next = 5 | [5, 8, 4, 3, 2, 0, 0]
      i reaches end.
      */
      for (int i = 0, next = 0; i < nums.size(); i++)
      {
         if (nums[i] != 0)
         {
            // `next` marks the end position of the non-zero numbers seen so far
            // therefore swapping these 2 will mean to put nums[i] to where it should be:
            // the end of the non-zero array
            swap(nums[i], nums[next]);
            next++;
         }
      }
   }
};