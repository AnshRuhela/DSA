class Solution {
  public:
    int find(vector<int>&arr,int k,int i,int n,vector<vector<int>>&dp)
    {
    	if(i==0)
    	{ 
    	    if(k==0 && arr[0]==0) return 2; // two cases either we take or not take that '0' so there can be two subsets can be made.
    	    if(k==0 || arr[0]==k) return 1; // ya to target hi zero ho agar first index pe 0 ke alawa kuch or hai to, or if target hi first index pe ho to 1 subset banega.  
    	    else return 0; 
    	}
    	if(dp[k][i]!=-1) return dp[k][i];
    	int ntake=find(arr,k,i-1,n,dp);
    	int take=0;
    	if(k>=arr[i])
    	{
    		take=find(arr,k-arr[i],i-1,n,dp);
    	}
    	return dp[k][i]= take+ntake;
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
          // code here
          int count=0;
          for(auto it : arr)
          {
              if(it==0) count++;
          }
          if(target==0) return pow(2,count);
        	int n=arr.size();
        	vector<vector<int>>dp(target+1,vector<int>(n,-1));
        	int ans= find(arr,target,n-1,n,dp);
        	return ans;
    
    }
};