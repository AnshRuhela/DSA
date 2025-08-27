/*
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
Example 2:

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
*/
class Solution {
public:
    //this is the code of lcs
    int lcs(int n, int m, string str1, string str2) {
        // we considered 1 based indexing means we are assuming the length of
        // the strings not the indexes.
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        for (int i = 0; i <= m; i++) {
            dp[0][i] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n][m];
    }
    int longestPalindromeSubseq(string s) {
        string Srev = s;
        reverse(Srev.begin(),Srev.end());
        int n = s.length();
        return lcs(n,n,s,Srev);
    }
};