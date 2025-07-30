class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,r=n-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(target==nums[mid])
            {
                return mid;
            }
            if(nums[mid]>=nums[l]) // kya left wala sorted hai.
            {
                if(target>=nums[l] && target<nums[mid]) // ager target left me hai.
                {
                    r=mid-1;
                }
                else
                {
                    l=mid+1; // agar target right me hai.
                }
            }
            else // agar right wala sorted hai.
            {
                 if(target>nums[mid] && target<=nums[r]) // agar target right me hai.
                {
                    l=mid+1; 
                }
                else // agar target left me hai.
                {
                    r=mid-1;
                }
            }
        }
        return -1;
    }
};