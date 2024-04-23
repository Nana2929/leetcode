#include<stack>
#include<string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i=0; i< s.length();i++){
            auto c = s[i];
            if (c == '(' || c == '[' || c == '{'){st.push(c);}
            else{
                if (!st.empty()){
                    if ((c == ']' && st.top() == '[')||
                    (c == ')' && st.top() == '(')||
                    (c == '}' && st.top() == '{')){st.pop();}
                    else{return false;}
                }
                else{return false;}
            }
        }
        return st.empty();
    }
};