#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;
/*
https://leetcode.com/problems/dota2-senate/description/?envType=study-plan-v2&envId=leetcode-75
*/
class Solution
{
public:

   bool isSameParty(queue<char> Q)
   {
      char prev = Q.front();
      while (!Q.empty())
      {
         if (prev != Q.front())
         {
            return false;
         }
         Q.pop();
      }
      return true;
   }
   char getReverseParty(char & x)
   {
      if (x == 'R') { return 'D'; }
      return 'R';
   }
   string predictPartyVictory(string senates)
   {
      unordered_map<char, string> names;
      names['R'] = "Radiant";
      names['D'] = "Dire";
      if (senates.length() == 1) { return names[senates[0]]; }
      unordered_map<char, int> bans;
      queue<char> Q;
      for (char c : senates)
      {
         Q.push(c);
      }
      while (!isSameParty(Q))
      {
         char senator = Q.front();
         Q.pop();
         if (bans[senator] > 0)
         {
            bans[senator]--;
         }
         else if (senator != Q.front())
         {
            Q.pop();
            Q.push(senator);
         }
         else
         {
            bans[getReverseParty(senator)] += 1;
            Q.push(senator);
         }
      }
      return names[Q.front()];
   }
};

int main()
{
   Solution s;
   string senates = "DDRRRR";
   cout << s.predictPartyVictory(senates) << endl;
   return 0;
}