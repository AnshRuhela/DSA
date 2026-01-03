/*
You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note:
->You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

->The transaction fee is only charged once for each stock purchase and sale.
 
Example 1:

Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
Example 2:

Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6
*/

class Solution {
public:
    int find(int ind , int buy , int n , int fee , vector<int> &prices , vector<vector<int>> &dp){
        if(ind == n) return 0;

        if(dp[ind][buy] != -1) return dp[ind][buy];

        int ntake = find(ind+1 , buy , n , fee , prices , dp);

        int take = -1e8;
        if(buy){
            take = -prices[ind] + find(ind+1 , !buy , n , fee , prices , dp);
        }
        else{
            take = (prices[ind] - fee) + find(ind+1 , !buy , n , fee , prices , dp);
        }
        return dp[ind][buy] = max(take , ntake);
    }
    int maxProfit(vector<int>& prices , int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return find(0,1,n,fee,prices,dp);
    }
};