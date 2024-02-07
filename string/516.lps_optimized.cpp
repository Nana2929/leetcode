#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

/*
TC: 89.57% O(n^2)
SC: 36.29% O(n^2)
*/

using namespace std;
class Solution {
public:
    vector<vector<int>> dp;
    int lcs(string& s, int l, int r){
        if (l > r){ return 0;}
        if ( l == r ){return 1;}
        if (dp[l][r] != -1){
            return dp[l][r];
        }
        if (s[l] == s[r]){
            dp[l][r] = lcs(s, l+1, r-1) +2;
        }
        else {
            dp[l][r] = max(lcs(s, l+1, r), lcs(s, l, r-1));
        }
        return dp[l][r];
    }
    int longestPalindromeSubseq(string s) {
        // no need to copy a string and reverse, just do it in place
        int n = s.size();
        dp = vector<vector <int>> (n, vector<int> (n, -1));
        for (int i = 0; i < n; i++){
            dp[i][i] = 1;
        }
        return lcs(s, 0, n-1);
    }
};