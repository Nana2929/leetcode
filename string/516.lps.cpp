#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

/*
Problem: Longest Common Palindrome Subsequence [Medium]
https://leetcode.com/problems/longest-palindromic-subsequence/description/

Description:
Given a string s, find the longest palindromic subsequence's length in s.
A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

Solution: lcs(s, reverse of s)

*/

class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int lcs(string& s, string& sr, int i, int j){
        if (dp[i+1][j+1] != -1){
            return dp[i+1][j+1];
        }
        if (!(i >= 0 && j>=0)){
            return 0;
        }

        if (s[i] == sr[j]){
            dp[i+1][j+1] = lcs(s, sr, i-1, j-1) +1;
        }
        else{
            dp[i+1][j+1] = max(lcs(s, sr, i-1, j), lcs(s, sr, i, j-1));
        }
        return dp[i+1][j+1];
    }
    int longestPalindromeSubseq(string s) {
        string sr= "";
        sr = s;
        reverse(sr.begin(), sr.end());
        n = s.size();
        dp = vector<vector<int>> (n+1, vector<int>(n+1, -1));
        for (int i =0; i < n; i++){
            dp[0][i] = 0;
            dp[i][0] = 0;
        }
        return lcs(s, sr, n-1, n-1);
        // https://stackoverflow.com/questions/1910712/dereference-vector-pointer-to-access-element
        // https://stackoverflow.com/questions/17663186/initializing-a-two-dimensional-stdvector
    }
};