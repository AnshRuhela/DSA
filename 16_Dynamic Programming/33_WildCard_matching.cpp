/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
*/
class Solution {
public:
    bool find(string &s, string &p , int len1 , int len2 , vector<vector<int>> &dp){

        if(len1 == 0 && len2 == 0) return true;  // means both the string are completed
        if(len2 == 0) return false; // means only pattern is complted not the string

        if(len1 == 0){ //means only string is completed not the pattern (now the pattern[ind2] can be * , ? or a character)
            for(int i = len2-1; i>=0; i--){
                if(p[i] != '*') return false;
            }
            return true;
        }

        if(dp[len1][len2] != -1) return dp[len1][len2];

        if(p[len2-1] == '?' || p[len2-1] == s[len1-1]){
            return dp[len1][len2] =  find(s,p,len1-1,len2-1,dp);
        }
        else if(p[len2-1] == '*'){
            int match = find(s,p,len1-1,len2,dp);
            int notmatch = find(s,p,len1,len2-1,dp);
            return dp[len1][len2] = (match || notmatch);
        }
        else{
            return dp[len1][len2] = false;
        }
    }
    bool isMatch(string s, string p) {
        int n1 = s.length();
        int n2 = p.length();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        return find(s,p,n1,n2,dp);
    }
};