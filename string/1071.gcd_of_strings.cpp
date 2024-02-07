#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

using namespace std;
class Solution
{
public:

   string gcdOfStrings(string str1, string str2)
   {
      // https://leetcode.com/problems/greatest-common-divisor-of-strings/solutions/3124940/c-one-line-beats-100-runtime-explanation
      if (str1 + str2 != str2 + str1)
      {
         return "";
      }
      int gcd_ = __gcd(str1.size(), str2.size());
      // c++14: <algorithm> __gcd
      // c++17: <numeric> gcd
      // https://www.geeksforgeeks.org/stdgcd-c-inbuilt-function-finding-gcd/
      return str1.substr(0, gcd_);
   }
};