#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:

   unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
   bool isVowel(char c)
   {
      return vowels.find(c) != vowels.end();
   }
   int maxi = 0;
   int maxVowels(string s, int k)
   {
      vector<int> d(s.length() + 1, 0);
      for (int i = 1; i <= s.length(); i++)
      {
         d[i] = d[i - 1];
         d[i] += (isVowel(s[i - 1])) ? 1 : 0;
      }
      for (int i = k; i <= s.length(); i++)
      {
         maxi = max(maxi, d[i] - d[i - k]);
      }
      return maxi;
   }
};

int main()
{
   Solution sol;
   cout << sol.maxVowels("weallloveyou", 7) << endl;
   return 0;
}