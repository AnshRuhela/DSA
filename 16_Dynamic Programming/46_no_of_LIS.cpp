class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> dp(n, 1); // dp[i] stores the length of the LIS ending at nums[i]
        vector<int> ct(n, 1); // ct[i] stores the count of LIS ending at nums[i]

        int maxi = 1; // Initialize the maximum length as 1

        for (int i = 0; i < n; i++)
        {
            for (int prev_index = 0; prev_index < i; prev_index++)
            {
                if (nums[prev_index] < nums[i] && dp[prev_index] + 1 > dp[i])
                {
                    dp[i] = dp[prev_index] + 1;
                    // Inherit count
                    ct[i] = ct[prev_index]; //means iske through kitne bane honge. // dry run this yourself.
                }
                else if (nums[prev_index] < nums[i] && dp[prev_index] + 1 == dp[i])
                {
                    // Increase the count
                    ct[i] = ct[i] + ct[prev_index]; // agar dubara equal aaya means count increase karna hai.
                }
            }
            maxi = max(maxi, dp[i]);
        }

        int numberOfLIS = 0;

        for (int i = 0; i < n; i++)
        {
            if (dp[i] == maxi)
            {
                numberOfLIS += ct[i];
            }
        }

        return numberOfLIS;
    }
};
