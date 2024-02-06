#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> opr_stack; // operator stack
        for (auto token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int opr2 = opr_stack.top();
                opr_stack.pop();
                int opr1 = opr_stack.top();
                opr_stack.pop();
                // if not opr1 and opr2, the prefix expression is invalid
                if (token == "+") {
                    opr_stack.push(opr1 + opr2);
                } else if (token == "-") {
                    opr_stack.push(opr1 - opr2);
                } else if (token == "*") {
                    opr_stack.push(opr1 * opr2);
                } else if (token == "/") {
                    opr_stack.push(opr1 / opr2);
                }
            } else {
                opr_stack.push(stoi(token));
            }
        }
        return opr_stack.top();

    }
};