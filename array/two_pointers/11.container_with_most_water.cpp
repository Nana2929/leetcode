#include <algorithm>
#include <vector>
using namespace std;
/*
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.
https://leetcode.com/problems/container-with-most-water/description/?envType=study-plan-v2&envId=leetcode-75

Greedy approach:
The idea is to place the bounds l and r,
and then move the bound by comparing the height[l] and height[r]; the higher one will be moved inwards.
The area is calculated by min(height[l], height[r]) * (r - l); after moving the bounds, the current area is recalculated and
compared with the previous max area.

*/
class Solution
{
public:

   int maxArea(vector<int> & height)
   {
      int l = 0;
      int r = height.size() - 1;
      int area = min(height[r], height[l]) * (r - l);
      while (l < r)
      {
         if (height[l] < height[r]) { l++; }
         else { r--; }
         area = max(area, min(height[r], height[l]) * (r - l));
      }
      return area;
   }
};