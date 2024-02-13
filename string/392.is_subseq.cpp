#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

class Solution
{
public:

   bool isSubsequence(std::string s, std::string t)
   {
      // binary search
      // thanks to @cdai and @bradypus  https://leetcode.com/problems/is-subsequence/solutions/87302/binary-search-solution-for-follow-up-with-detailed-comments/comments/172906
      // 1. make a hash table of char: list of indices the char occurs (sorted)
      std::unordered_map<char, std::vector<int>> hash;
      for (int i = 0; i < t.length(); i++)
      {
         hash[t[i]].push_back(i);
      }
      // 2. use a variable `prev` to record the position of the found char in `t`
      // 3. traverse string `s`, if char c in s presents in t (== found in hash table).
      // use `prev` to index to the `index position of c that is just greater than prev`, and then use
      // this index to update `prev`
      // for finding ``index position of c that is greater than prev``, use ``binary search``
      // i.e. Keep record of all prev as an array, with s = `ade` t= `abcde`, you get [0,3,4]

      int prev = -1;
      for (auto c : s)
      {
         auto iter = hash.find(c);
         if (iter == hash.end())
         {
            return false;
         }
         std::vector<int> c_indices = iter->second;
         int pos = std::upper_bound(c_indices.begin(), c_indices.end(), prev) - c_indices.begin();
         // if pos == c_indices.size(), meaning this position within the current c_indices can not be found,
         // in turn meaning all of c in string t has been matched and used up by previous c-es in string s
         if (pos == c_indices.size())
         {
            return false;
         }
         prev = c_indices[pos];
      }
      return true;
   }
};