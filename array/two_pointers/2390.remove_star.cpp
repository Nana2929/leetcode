#include <iostream>
#include <stack>
#include <string>
#include <algorithm> // reverse
using namespace std;

/*
2390. Remove Stars from A String
https://leetcode.com/problems/removing-stars-from-a-string/description/?envType=study-plan-v2&envId=leetcode-75
Input: s = "leet**cod*e"
Output: "lecoe"
Explanation: Performing the removals from left to right:
- The closest character to the 1st star is 't' in "leet**cod*e". s becomes "lee*cod*e".
- The closest character to the 2nd star is 'e' in "lee*cod*e". s becomes "lecod*e".
- The closest character to the 3rd star is 'd' in "lecod*e". s becomes "lecoe".
There are no more stars, so we return "lecoe".

*/
class Solution1 {
public:
    string removeStars(string s) {
        /*
        1. stack*
        2. two-pointers
        */
        stack<char> st;
        for (char c: s){
            if (c == '*'){
                if (!st.empty()){st.pop();}
            }
            else{st.push(c);}
        }
        // pour the st out
        string out;
        while (!st.empty()){out.push_back(st.top());st.pop();}
        reverse(out.begin(), out.end());
        return out;
    }
};

class Solution2 {
public:
    string removeStars(string s) {
        /*
        1. stack
        2. two-pointers*
        Two-pointer requires in-place modification
        */
        int i=0,j=0;
        for (int i = 0; i <s.length();i++){
            if (s[i]!='*'){
                s[j++]=s[i];}
            else{j--;}
        }
        return s.substr(0,j);
    }
};