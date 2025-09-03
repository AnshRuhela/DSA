class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>arr;
        arr.push_back(nums[0]);

        for(int i=1;i<n;i++)
        {
            if(arr.back()<nums[i])
            {
                arr.push_back(nums[i]);
            }
            else // in this else we are finding the lower bound menas index of the number which is > or = to the nums[i] in arr.
            {
                int l=0,r=arr.size()-1;
                int num=nums[i];
                int ind=i;
                while(l<=r)
                {
                    int mid=(l+r)/2;
                    if(arr[mid]==num)
                    {
                        ind=mid;
                        break;
                    }
                    else if(num>arr[mid]) // we have to find >= if arr[mid]<num means vo aage hi milega and ye vo number ho hi nahi sakta.
                    {
                        l=mid+1;
                    }
                    else
                    {
                        r=mid-1;
                        ind=mid;
                    }
                }
                arr[ind]=num;
            }
        }
        return arr.size();
    }
};