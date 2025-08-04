class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1 ) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-1]!=nums[n-2]) return nums[n-1];// we handled the test cases to not to write th edge cases later in the code
        int l=1,r=n-2; // we don't take l=0,r=n-1 so that edge cases don't disturb later.
        int ans;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(mid%2==0)
            {   
                if(nums[mid]!=nums[mid+1])
                {
                    ans= nums[mid];
                    r=mid-1;
                }
                else
                {
                    l=mid+1;
                }
            }
            else
            {
                if(nums[mid]!=nums[mid-1])
                { 
                    r=mid-1;
                }
                else
                {
                    l=mid+1;
                }
            }
        }
        return ans;
    }
};