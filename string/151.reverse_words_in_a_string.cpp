
#include <sstream>
#include <stack>
#include <string>
using namespace std;

class Solution
{
public:

   string reverseWords(string s)
   {
      stack<string> st;
      // use `stringstream` to process space-sep string
      stringstream ss(s);
      string tmp;
      while (ss >> tmp)
      {
         st.push(tmp);
      }
      string res = "";
      while (!st.empty())
      {
         res.append(st.top());
         st.pop();
         if (!st.empty()) { res.append(" "); }
      }
      // 重複使用 stringstream
      ss.str("");
      ss.clear();
      return res;
   }
};