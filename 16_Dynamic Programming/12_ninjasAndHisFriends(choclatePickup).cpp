/*
Problem statement
Ninja has a 'GRID' of size 'R' X 'C'. Each cell of the grid contains some chocolates. Ninja has two friends Alice and Bob, and he wants to collect as many chocolates as possible with the help of his friends.

Initially, Alice is in the top-left position i.e. (0, 0), and Bob is in the top-right place i.e. (0, ‘C’ - 1) in the grid. Each of them can move from their current cell to the cells just below them. When anyone passes from any cell, he will pick all chocolates in it, and then the number of chocolates in that cell will become zero. If both stay in the same cell, only one of them will pick the chocolates in it.

If Alice or Bob is at (i, j) then they can move to (i + 1, j), (i + 1, j - 1) or (i + 1, j + 1). They will always stay inside the ‘GRID’.

Your task is to find the maximum number of chocolates Ninja can collect with the help of his friends by following the above rules.

Example:
Input: ‘R’ = 3, ‘C’ = 4
       ‘GRID’ = [[2, 3, 1, 2], [3, 4, 2, 2], [5, 6, 3, 5]]
Output: 21

Initially Alice is at the position (0,0) he can follow the path (0,0) -> (1,1) -> (2,1) and will collect 2 + 4 + 6 = 12 chocolates.

Initially Bob is at the position (0, 3) and he can follow the path (0, 3) -> (1,3) -> (2, 3) and will colllect 2 + 2 + 5 = 9 chocolates.

Hence the total number of chocolates collected will be 12 + 9 = 21. there is no other possible way to collect a greater number of chocolates than 21.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= ‘T’ <= 10
2 <= 'R', 'C' <= 50
0 <= 'GRID[i][j]'<= 10^2
Time Limit: 1sec
Sample Input 1 :
2
3 4
2 3 1 2
3 4 2 2
5 6 3 5
2 2
1 1
1 2
Sample Output 1 :
21
5
Explanation Of Sample Input 1 :
For the first test case, Initially Alice is at the position (0, 0) he can follow the path (0, 0) -> (1, 1) -> (2, 1) and will collect 2 + 4 + 6 = 12 chocolates.

Initially Bob is at the position (0, 3) and he can follow the path (0, 3) -> (1, 3) -> (2, 3) and will collect 2 + 2 + 5 = 9 chocolates.

Hence the total number of chocolates collected will be 12 + 9 = 21.

For the second test case, Alice will follow the path (0, 0) -> (1, 0) and Bob will follow the path (0, 1) -> (1, 1). total number of chocolates collected will be 1 + 1 + 1 + 2 = 5
Sample Input 2 :
2
2 2
3 7
7 6
3 2
4 5
3 7
4 2
Sample Output 2 :
23
25
*/

#include <bits/stdc++.h> 

int find(vector<vector<int>>&grid,int r,int c, int i,int j1,int j2,vector<vector<vector<int>>>&dp)
{
    if(j1<0 || j1==c || j2<0 || j2==c) // agar out of bound gya 
    {
        return -1e9;
    }
    if(i==r-1) 
    {
        if(j1==j2) return grid[i][j1]; // agar dono same cell me hue
        else return grid[i][j1]+grid[i][j2];
    }

    if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];

    int ans=-1e8;
    int dj[]={-1,0,1};
    for(auto k : dj) // trying all the possible combinations.
    {
        for(auto l:dj)
        {
            int cc1=j1+k;
            int cc2=j2+l;
            int ans2=0;
            if(j1==j2) // again agar dono same call me hue.
            {
                ans2=grid[i][j1]+find(grid,r,c,i+1,cc1,cc2,dp);
            }
            else // verna dono ka sum plus hoga.
            {
                ans2=grid[i][j1]+grid[i][j2]+find(grid,r,c,i+1,cc1,cc2,dp);
            }
            ans=max(ans,ans2);
        }
    }
    return dp[i][j1][j2]= ans;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
    return find(grid,r,c,0,0,c-1,dp);
}