// same as allocate books problem

class Solution {
public:
int findLargest(vector<int>&nums)
    {
        int large=INT_MIN;
        for(auto it : nums)
        {
            large=max(large,it);
        }
        return large;
    }

    int findSum(vector<int>&nums)
    {
        int s=0;
        for(auto it : nums)
        {
            s+=it;
        }
        return s;
    }
    int findSplitsRequired(vector<int>&nums,int n,int pages)
    {
        int req=1;
        int page=nums[0];
        for(int i=1;i<n;i++)
        {
            if(page+nums[i]>pages)
            {
                req++;
                page=nums[i];
            }
            else
            {
                page+=nums[i];
            }
        }
        return req;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int l=findLargest(nums);
        int h=findSum(nums);
        int ans;
        while(l<=h)
        {
            int mid=(l+h)/2;
            int splits=findSplitsRequired(nums,n,mid);
            if(splits<=k)
            {
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};