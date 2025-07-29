class Solution {
public:
    vector<int>findNge(vector<int>nums)
    {
        int n=nums.size();
        stack<int>st;
        vector<int>nge(n);

        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && nums[st.top()]<=nums[i] )
            {
                st.pop();
            }
            
            {
                if(st.empty())
                {
                    nge[i]=n;
                }
                else
                {
                    nge[i]=st.top();
                }
                st.push(i);
            }
        }
        return nge;
    }

    vector<int>findPgee(vector<int>nums)
    {
        int n=nums.size();
        stack<int>st;
        vector<int>pgee(n);

        for(int i=0;i<n;i++)
        {
            while(!st.empty() && nums[st.top()]<nums[i] )
            {
                st.pop();
            }
            
            {
                if(st.empty())
                {
                    pgee[i]=-1;
                }
                else
                {
                    pgee[i]=st.top();
                }
                st.push(i);
            }
        }
        return pgee;
    }

      vector<int>findNse(vector<int>nums)
    {
        int n=nums.size();
        stack<int>st;
        vector<int>nse(n);

        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && nums[st.top()]>=nums[i] )
            {
                st.pop();
            }
            
            {
                if(st.empty())
                {
                    nse[i]=n;
                }
                else
                {
                    nse[i]=st.top();
                }
                st.push(i);
            }
        }
        return nse;
    }

      vector<int>findPsee(vector<int>nums)
    {
        int n=nums.size();
        stack<int>st;
        vector<int>psee(n);

        for(int i=0;i<n;i++)
        {
            while(!st.empty() && nums[st.top()]>nums[i] )
            {
                st.pop();
            }
            
            {
                if(st.empty())
                {
                    psee[i]=-1;
                }
                else
                {
                    psee[i]=st.top();
                }
                st.push(i);
            }
        }
        return psee;
    }

    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        
        vector<int>nge(n),pgee(n),nse(n),psee(n);
        nge=findNge(nums);
        pgee=findPgee(nums);
        nse=findNse(nums);
        psee=findPsee(nums);
        long long miniSum=0;
        long long maxSum=0;
        for(int i=0;i<n;i++)
        {
            miniSum+=((nse[i]-i)*(i-psee[i])*1LL*nums[i]);
            maxSum+=(nge[i]-i)*(i-pgee[i])*1LL*nums[i];
        }
        return maxSum-miniSum;

    }
};