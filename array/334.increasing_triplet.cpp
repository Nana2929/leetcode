#include<vector>
#include<climits>
using namespace std;
class Solution
{
public:

   bool increasingTriplet(vector<int> & nums)
   {
      // thanks to @sim5
      /*
      No need of 2 pointers!!
      the idea is to keep track of the i's value and j's value
      update these 2 values so they are always the lowest bound
      and if you find a value greater than both then an increasing triplet is found.
      */
      int ival = INT_MAX;
      int jval = INT_MAX;
      for (auto & n : nums)
      {
         if (n <= ival) { ival = n; }       // update this first
         else if (n <= jval) { jval = n; }  // note that this is ELSE IF, this way jval is slightly larger than ival but is the lowest {SECOND LOWEST}
         else { return true; }              // n > ival && n > jval; naturally jval > ival.
      }
      return false;
   }
};