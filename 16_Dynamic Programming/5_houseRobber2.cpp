class Solution {
public:
    // this is code for(House Robber 1)
    int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();


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
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0]; // if n == 1 so temp2 will have 0 element
        vector<int> temp1 , temp2;
        for(int i = 0; i<n; i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }
        int ans1 = maximumNonAdjacentSum(temp1);
        int ans2 = maximumNonAdjacentSum(temp2);
        return max(ans1,ans2);
    }
};