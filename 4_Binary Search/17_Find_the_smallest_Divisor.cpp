class Solution {
public:
    int findMax(vector<int>&nums)
    {
        int maxi=INT_MIN;
        for(auto it : nums)
        {
            maxi=max(maxi,it);
        }
        return maxi;
    }
    int find(vector<int>&nums,int div)
    {
        int sum=0;
        for(auto it : nums)
        {
            sum+=ceil((double)it/div);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int l=1;
        int r=findMax(nums);
        while(l<=r)
        {
            int mid=(l+r)/2;
            int sum=find(nums,mid);
            if(sum<=threshold)
            {
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return l;
    }
};