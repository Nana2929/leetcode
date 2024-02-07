/*
605. Can Place Flowers
https://leetcode.com/problems/can-place-flowers/description/?envType=study-plan-v2&envId=leetcode-75
You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.

Example 1:

Input: flowerbed = [1,0,0,0,1], n = 1
Output: true
Example 2:

Input: flowerbed = [1,0,0,0,1], n = 2
Output: false

*/
#include <vector>
using namespace std;
class Solution
{
public:

   bool canPlant(int i, vector<int> & flowerbed)
   {
      size_t size = flowerbed.size();
      if (i - 1 < 0 || flowerbed[i - 1] == 0)
      {
         if (i + 1 >= size || flowerbed[i + 1] == 0)
         {
            return true;
         }
      }
      return false;
   }
   bool canPlaceFlowers(vector<int> & flowerbed, int n)
   {
      /*greedy will work.*/
      int result = 0;
      if (n == 0) { return true; }
      for (int i = 0; i < flowerbed.size(); i++)
      {
         if (flowerbed[i] == 1) { continue; }
         int x = canPlant(i, flowerbed);  // implicit type-conversion from bool to int
         result += x;
         flowerbed[i] = x;
         // trick: use an early stop here
         if (result >= n)
         {
            return true;
         }
      }
      return false;
      // return result >= n;
   }
};