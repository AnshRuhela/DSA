

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
    int findStudentsRequired(vector<int>&nums,int n,int pages)
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
    int findPages(vector<int> &nums, int m)  {
        int n=nums.size();
        if(m>n) return -1;
        int l=findLargest(nums);
        int h=findSum(nums);
        int ans;
        while(l<=h)
        {
            int mid=(l+h)/2;
            int studs=findStudentsRequired(nums,n,mid);
            if(studs<=m) // mena we can allocate pages to students but we have to minimize the maximum pages allocated to a student
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