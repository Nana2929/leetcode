#include<vector>
#include<string>
using namespace std;
// thanks to @peace
// https://leetcode.com/problems/generate-parentheses/solutions/10105/concise-recursive-c-solution/comments/11032
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        adding(res, "", n, n);
        return res;

    }
    void adding(vector<string>&v, string s, int left, int right){
        if (left == 0 && right == 0){
            v.push_back(s);
            return;
        }
        if (left > 0){adding(v, s+"(", left-1, right);}
        // right parenthesis can only be added if the existing string `s` has more open parenthesis than closed ones
        if (right > left){adding(v, s+")", left, right-1);}

    }
};