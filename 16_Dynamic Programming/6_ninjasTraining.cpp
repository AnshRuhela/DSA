#include<bits/stdc++.h>

int find(int n,vector<vector<int>>&points,int prev,int day,vector<vector<int>>&dp)
{
  if(day==0)
  {
    int maxi=INT_MIN;
    for(int i=0;i<3;i++)
    {
      if(i!=prev)
      {
        maxi=max(maxi,points[0][i]);
      }
    }
    return maxi;
  }
  if(dp[day][prev]!=-1) return dp[day][prev];

  int maxi=INT_MIN;
  for(int i=0;i<3;i++)
  {
    int tr=INT_MIN;
    if(prev!=i)
    {
      tr=points[day][i]+find(n,points,i,day-1,dp);
    }
    maxi=max(maxi,tr);
  }

  return dp[day][prev]= maxi;

}

int ninjaTraining(int n, vector<vector<int>> &points)
{
  vector<vector<int>>dp(n,vector<int>(4,-1));
    // return find(n,points,3,n-1,dp);

    dp[0][0]=max(points[0][1],points[0][2]);
    dp[0][1]=max(points[0][0],points[0][2]);
    dp[0][2]=max(points[0][0],points[0][1]);
    dp[0][3]=max(points[0][1],max(points[0][0],points[0][2]));
    for(int day=1;day<n;day++)
    {
      for(int prev=3;prev>=0;prev--)
      {
        int maxi=INT_MIN;
        for(int i=0;i<3;i++)
        {
          int tr=INT_MIN;
          if(prev!=i)
          {
            tr=points[day][i]+dp[day-1][i];
          }
          maxi=max(maxi,tr);
        }
        dp[day][prev]=maxi;
      }
    }

  return dp[n-1][3];

}



/*


purana

int fun( vector<vector<int>> &points, int ind, int prev,vector<vector<int>> &dp) {
  if (ind == 0) { // agar index zero aai means day 0
   int   maxi=0;
      for (int i = 0; i < 3; i++) {
        if (i != prev) { // previous task nahi perform karna chahiye
         maxi=max(maxi,points[0][i]);  // day 0 ka maximum nikala
        }
      }
         return maxi; // return kardiya maxm in day 0 
  } 
  if (dp[ind][prev] != -1) return dp[ind][prev];
      int maxim=0;
      for (int i = 0; i < 3; i++) {
         
        if (i != prev) {
           int  pts=points[ind][i]+fun(points,ind-1,i,dp);
        maxim=max(maxim,pts);
        }
      }
      return dp[ind][prev]=maxim; 
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n,vector<int> (4,-1)); // for memoization
    return fun(points,n-1,3,dp);
}
*/
