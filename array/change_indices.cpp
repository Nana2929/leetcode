#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{

public:

   /* thanks to @k487237
   https://leetcode.com/problems/earliest-second-to-mark-indices-i/solutions/4778573/c-binary-search-easy-understand*/
   bool check(vector<int> & nums, vector<int> & changeIndices, int idx)
   {
      /*
      check if by `idx` second, we can mark all indices or not
      */
      // make a map that stores the lastPossibleSecond to mark each index
      unordered_map<int, int> lastSecond;
      for (int i = 0; i < nums.size(); i++)
      {
         // num_index = last second (will be overwritten again & again)
         lastSecond[changeIndices[i]] = i;
      }
      // the made map is supposedly be the same size of nums
      if (lastSecond.size() != nums.size()) { return false; }
      // check that "by the second `idx`",
      // can the changeIndices[idx] number be decreased and marked?
      // we maintain `dec_count` as a counter for storing decrease operations;
      // we can use this counter to decrease a number at once
      int dec_count = 0;
      for (int i = 0; i < idx; i++)
      {
         // case 1
         if (i == lastSecond[changeIndices[i]])
         {
            // if at second `i`, we encounter the lastsecond possible to mark a number
            // we use dec_count to try to do this (beware of nums' 1-indexed)
            // case 1.1: no enough dec_count to mark this number
            if (dec_count < nums[changeIndices[i] - 1]) { return false; }
            // case 1.2: enough dec_count, we spend dec_count to mark the number
            else { dec_count -= nums[changeIndices[i] - 1]; }
         }
         // case 2
         else
         {
            // this second is not the lastSecond for anyone, we simply save dec_count
            // for future case 1
            dec_count++;
         }
      }
      return true;
   }
   int earliestSecondToMarkIndices(vector<int> & nums, vector<int> & changeIndices)
   {
      // use a for loop to check every second
      // or better, use binary search to check
      int l = 0, r = changeIndices.size() + 1;  // !inclusive
      while (l < r)
      {
         cout << "r: " << r << endl;
         int mid = l + (r - l) / 2;
         cout << "mid: " << mid << endl;
         if (check(nums, changeIndices, mid))
         {
            r = mid;
         }
         else
         {
            l = mid + 1;
         }
      }
      // after the process, l >= r, the right bound `r` is the earliest possible second
      // for all indices to be marked.

      return r > changeIndices.size() ? -1 : r;
   }
};

int main()
{
   Solution s;
   vector<int> nums = {1, 1, 1, 1};
   vector<int> changeIndices = {1, 2, 3, 4};
   int res = s.earliestSecondToMarkIndices(nums, changeIndices);
   cout << res << endl;  // 1
   return 0;
}