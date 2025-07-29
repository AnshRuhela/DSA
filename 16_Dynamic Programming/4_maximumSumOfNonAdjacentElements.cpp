/*

You are given an array/list of ‘N’ integers. You are supposed to return the maximum sum of the subsequence with the constraint that no two elements are adjacent in the given array/list.

Note:
A subsequence of an array/list is obtained by deleting some number of elements (can be zero) from the array/list, leaving the remaining elements in their original order.

*/


 #include <bits/stdc++.h> 
int find(int ind , vector<int> &nums , vector<int> &dp){
    if(ind == 0) return nums[ind];
    if(ind<0) return 0;
    if(dp[ind] != -1) return dp[ind];

    int take = nums[ind] + find(ind-2 , nums,dp);
    int ntake = find(ind-1,nums,dp);
    return dp[ind] = max(take,ntake);
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    vector<int> dp(n,-1);
    // return find(n-1,nums,dp);

    //base case
    //tabulation without space optimization
    // dp[0] = nums[0];
    // for(int ind = 1; ind<n; ind++){
    //     int take = nums[ind];
    //     if(ind>1) take += dp[ind-2];  //(base case)this is because if(i<=1) then dp[ind-2] will be out of bound
    //     int ntake = dp[ind-1];
    //     dp[ind] = max(take,ntake);
    // }
    // return dp[n-1];

    //tabulation with space optimization
    int prev1 = nums[0];
    int prev2;
    for(int ind = 1; ind<n; ind++){
        int take = nums[ind];
        if(ind>1) take += prev2;

        int ntake = prev1;
        int curr = max(take,ntake);

        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;

}