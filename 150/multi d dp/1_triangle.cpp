class Solution
{
public:
    int find(vector<vector<int>> &triangle, int i, int row, vector<vector<int>> &dp)
    {

        if (row == triangle.size())
            return 0;
        if (dp[row][i] != -1)
            return dp[row][i];
        int currTake = triangle[row][i] + find(triangle, i, row + 1, dp);
        int currNotTake = INT_MAX;
        if (i + 1 < triangle[row].size())
            currNotTake = triangle[row][i + 1] + find(triangle, i + 1, row + 1, dp);
        return dp[row][i] = min(currTake, currNotTake);
    }
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int rows = triangle.size();
        int maxCol = triangle[rows - 1].size();
        vector<vector<int>> dp(rows, vector<int>(maxCol, -1));
        return find(triangle, 0, 0, dp);

        // for(int i=0;i<triangle[rows-1].size();i++)
        // {
        //     dp[rows-1][i]=triangle[rows-1][i];
        // }

        // for(int row=rows-2;row>=0;row--)
        // {
        //     for(int i=triangle[row].size()-1;i>=0;i--)
        //     {
        //         int currTake=triangle[row][i]+dp[row+1][i];
        //         int currNotTake=INT_MAX;
        //         if(i+1<triangle[row].size())
        //         currNotTake=triangle[row][i+1]+dp[row+1][i+1];
        //         dp[row][i]= min(currTake,currNotTake);
        //     }
        // }

        // return dp[0][0];
    }
};