//  this is actual code and below this code we have another approch which is take or notake approch. where we did't use dp, we may use dp.
class Solution {
public:
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

        return dp[k][i] = (take + ntake);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
      int n=nums.size();
        int totalSum=0;
    for(auto it : nums)
    {
        totalSum+=it;
    }    
    if((totalSum-target)<0 || (totalSum-target)%2!=0) return 0;
    int newTarget=(totalSum-target)/2;
    vector<vector<int>>dp(newTarget+1,vector<int>(n,-1));
    return find(nums,newTarget,n-1,n,dp);

    }
};

/*

// below problem is done using take or ntake approch. but dp is not applied in below.

class Solution {
public:
    int find(vector<int>&nums,int target,int n,int i)
    {
        if(i==0)
        {
            if(target==0 && nums[0]==0) return 2; // agar index ==0 hai and target ==0 and nums[0]==0 then we can assign + or - to nums[0] target will still same so we have 2 ways
            if(target-nums[0]==0) return 1; // agar index 0 pe nums[0] ko minus kiya agar target 0 aagaya means ye bhi case hai.
            if(target+nums[0]==0) return 1; // agar index 0 pe nums[0] ko plus kiya agar target 0 aagaya means ye bhi case hai.
            return 0; 
        }

        int min=find(nums,target-nums[i],n,i-1); // we we assign minus sign to ith element
        int add=find(nums,target+nums[i],n,i-1); // we we assign plus sign to ith element
        return min+add;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return find(nums,target,n,n-1);
    }
};
*/