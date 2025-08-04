#include <bits/stdc++.h> 

int mod=1e9+7;
int find(vector<int>& arr, int k, int i, int n, vector<vector<int>>& dp) {
        if(i==0)
    	{
    	    if(k==0 && arr[0]==0) return 2;
    	    if(k==0 || arr[0]==k) return 1;
    	    else return 0;
    	}
        if (dp[k][i] != -1) return dp[k][i];

        int ntake = find(arr, k, i - 1, n, dp);
        int take = 0;
        if (k >= arr[i])
            take = find(arr, k - arr[i], i - 1, n, dp);

        return dp[k][i] = (take + ntake)%mod;
    }

int countPartitions(int n, int d, vector<int> &arr) {
    int totalSum=0;
    for(auto it : arr)
    {
        totalSum+=it;
    }    
    if((totalSum-d)<0 || (totalSum-d)%2!=0) return 0;
    int newTarget=(totalSum-d)/2;
    vector<vector<int>>dp(newTarget+1,vector<int>(n,-1));
    return find(arr,newTarget,n-1,n,dp);
}


