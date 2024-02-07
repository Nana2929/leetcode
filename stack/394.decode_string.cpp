#include <string>
using namespace std;

/*
394. Decode String
Leetcode Medium
Thanks to @5nooze (https://leetcode.com/problems/decode-string/solutions/87544/clean-c-recursive-solution-with-explanation)
The tricky point in this approach is that `pos` is global (pass by reference),
and it uses recursion which will move pos forward in each function call.
1. L#18 is essential in recording the current character otherwise L#23 will modify it.
2. The idea is, we use `num` to record mul time, and `word` to record solution string.
    L#20 increments the multiplication time'.
    L#23 and L#27 solve subproblem(s) (the internal brackets inside a string) by multiplying the bracket string by `num`.
    L#31 sees a normal alphabet so we concatenate it to word.
*/
class Solution
{
public:

   int ctoi(char x)
   {
      return x - '0';
   }
   string helper(int & pos, string s)
   {
      // pos is modified in-place over all function calls.
      int num = 0;
      string word = "";
      for (; pos < s.length(); ++pos)
      {
         char c = s[pos];
         if (isdigit(c))
         {
            num = num * 10 + ctoi(c);
         }
         else if (c == '[')
         {
            string substring = helper(++pos, s);
            for (; num > 0; num--) { word += substring; }  // for `num` times
         }
         else if (c == ']')
         {
            return word;
         }
         else
         {
            // an alphabet
            word += c;
         }
      }
      return word;
   }
   string decodeString(string s)
   {
      // return helper(0, s); // very interesting, cannot see
      int pos = 0;
      return helper(pos, s);
   }
};