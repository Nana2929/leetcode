#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
class Solution
{
public:

   std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> & strs)
   {
      // std::string sortedWord = word;
      // std::sort(sortedWord.begin(), sortedWord.end());
      std::unordered_map<std::string, std::vector<std::string>> m;
      for (auto & str : strs)
      {
         std::string sorted_str = str;
         std::sort(sorted_str.begin(), sorted_str.end());
         m[sorted_str].push_back(str);
      }
      std::vector<std::vector<std::string>> res;
      for (auto & it : m)
      {
         res.push_back(it.second);
      }
      return res;
   }
};
