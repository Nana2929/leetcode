#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution
{
public:

   string reverseVowels(string s)
   {
      stack<char> vstack;
      vector<char> tmp;
      unordered_set<char> vowels({'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'});
      for (auto & c : s)
      {
         // consonant
         // O(1) access
         if (vowels.find(c) == vowels.end())
         {
            tmp.push_back(c);
         }
         else
         {
            tmp.push_back('*');
            vstack.push(c);
         }
      }
      string ans = "";
      for (int i = 0; i < s.size(); i++)
      {
         if (tmp[i] == '*')
         {
            ans.push_back(vstack.top());
            vstack.pop();
         }
         else
         {
            ans.push_back(tmp[i]);
         }
      }
      return ans;
   }
};