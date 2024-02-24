#include <map>
#include <queue>
#include <vector>
using namespace std;
/*
2092. Find all people with secret
Level: Hard
Time spent: 57 minutes (with ChatGPT's aid)
https://leetcode.com/problems/find-all-people-with-secret/solutions/4774262/c-priority-queue

*/
typedef pair<int, int> pi;
#define SENTINEL 1e+8
class Solution
{
public:

   vector<int> findAllPeople(int n, vector<vector<int>> & meetings, int src)
   {
      vector<map<int, vector<int>>> graph(n);
      // u: time: v
      vector<int> ans;
      vector<int> informed(n, SENTINEL);
      ans.reserve(n);
      for (auto m : meetings)
      {
         graph[m[0]][m[2]].push_back(m[1]);  // sorted by time order internally for `map`
         graph[m[1]][m[2]].push_back(m[0]);  // bidirectional
      }
      priority_queue<pi, vector<pi>, greater<pi>> pq;

      pq.push({0, 0});
      informed[0] = 0;
      pq.push({0, src});
      informed[src] = 0;
      while (!pq.empty())
      {
         pi top = pq.top();
         pq.pop();
         auto [time, curr] = top;
         // the next meeting happens at time `time` with secret holder `curr`
         if (time > informed[curr]) continue;
         auto it = graph[curr].lower_bound(time);
         // it is an iterator of all times eq or greater than `time`
         for (; it != graph[curr].end(); ++it)
         {
            int meet_time = it->first;
            for (auto neighbor : it->second)
            {
               // push into the pq if this neighbor is not earlier informed
               if (informed[neighbor] == SENTINEL || informed[neighbor] > meet_time)
               {
                  informed[neighbor] = meet_time;
                  pq.emplace(it->first, neighbor);
               }
            }
         }
      }
      for (int i = 0; i < n; i++)
      {
         if (informed[i] < SENTINEL) { ans.push_back(i); }
      }
      return ans;
   }
};