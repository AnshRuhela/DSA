class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=n-1;
        int min=INT_MAX;
        while(l<=r)
        
        {
            int mid=(l+r)/2;
            if(nums[mid]<min)
            {
                min=nums[mid];
            }  
            if(nums[mid]>nums[r])
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }

        }
        return min;
    }
};