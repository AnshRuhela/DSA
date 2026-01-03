/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
Example 2:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 3:

Input: nums = [1,2,3]
Output: 3
*/

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