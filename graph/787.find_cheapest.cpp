#include <climits>
#include <iostream>
#include <queue>
#include <vector>
/*
787. Cheapest Flights Within K Stops
Level: Medium
Thanks to @brendon4565
https://leetcode.com/problems/cheapest-flights-within-k-stops/solutions/115596/c-8-line-bellman-ford
*/
using namespace std;
class Solution
{
public:

   int findCheapestPrice(int n, vector<vector<int>> & flights, int src, int dst, int k)
   {
      vector<long long> dp(n, 1e+10);
      dp[src] = 0;
      int u, v, w;
      for (int step = 0; step <= k; step++)
      {
         // make a copy so that values for this step do not overwrite previous steps
         vector<long long> dp_(dp);
         for (auto flight : flights)
         {
            u = flight[0];
            v = flight[1];
            w = flight[2];
            dp_[v] = min(dp_[v], dp[u] + w);  // note that we strictly need to writ like this
                                              // we are updating v at current step (hence `dp_[v]`), and compare it with previous step's values
                                              // (hence `dp[u]`).
         }
         dp = dp_;
      }
      return dp[dst] == 1e+10 ? -1 : dp[dst];
   }
};

int main()
{
   Solution s;
   // [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]]

   vector<vector<int>> flights = {
      {0, 1, 100},
      {1, 2, 100},
      {2, 0, 100},
      {1, 3, 600},
      {2, 3, 200}
   };
   cout << s.findCheapestPrice(4, flights, 0, 3, 1) << endl;
   return 0;
}