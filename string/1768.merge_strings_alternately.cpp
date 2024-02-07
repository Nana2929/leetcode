#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
class Solution
{
public:

   string mergeAlternately(string word1, string word2)
   {

      size_t min_size = min(word1.size(), word2.size());
      string res = "";
      for (int i = 0; i < min_size; i++)
      {
         res.push_back(word1[i]);  // string[i] is a character
         res.push_back(word2[i]);
      }
      // append the rest
      if (min_size < word1.size())
      {
         res.append(word1.substr(min_size, word1.size()));
      }
      if (min_size < word2.size())
      {
         res.append(word2.substr(min_size, word2.size()));
      }
      return res;
   }
};