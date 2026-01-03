/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.
*/

// normal for loop approch , whenever got the profit just add it and move on to next.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i=0,j=i+1;
        int profit=0;
        while(j<prices.size()) 
        {
            if(prices[j]-prices[i]>0)
            {
                profit+=prices[j]-prices[i];
            }
            i++;
            j++;
        }
        return profit;
    }
};

// dp approch



class Solution {
public:
    int find(vector<int> &prices , int n , int ind , int buy , vector<vector<int>> &dp){

        if(ind == n) return 0;

        if(dp[ind][buy] != -1) return dp[ind][buy];

        int ntake = find(prices ,n , ind+1 , buy , dp);

        int take = -1e8;
        if(buy){
            take = -prices[ind] + find(prices ,n,ind+1,!buy,dp);
        }
        else{
            take = prices[ind] + find(prices,n  , ind + 1 , !buy , dp);
        }
        return dp[ind][buy] = max(take,ntake);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return find(prices , n ,0,1,dp);
    }
};