

#include <iostream>
#include <vector>
using namespace std;
/*
Leetcode
443. String Compression
https://leetcode.com/problems/string-compression/description/?envType=study-plan-v2&envId=leetcode-75

*/
class Solution
{
public:

   int compress(vector<char> & chars)
   {
      int lead = 0;  // leading pointer of the revised vector
      int i = 0;     // leading pointer of the original vector
      while (i < chars.size())
      {
         char x = chars[i];
         int number = 0;
         while (i < chars.size() && chars[i] == x)
         {
            i++;
            number++;
         }
         string numstr = to_string(number);
         chars[lead++] = x;
         if (number > 1)
         {
            for (char c : numstr)
            {
               chars[lead++] = c;
            }
         }
      }
      return lead;
   }
};

int main()
{
   Solution s;
   // ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
   vector<char> chars = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
   int result = s.compress(chars);
   cout << result << endl;
   return 0;
}