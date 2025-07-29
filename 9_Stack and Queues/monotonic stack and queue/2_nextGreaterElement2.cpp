class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=2*n-1;i>=0;i--)
        {
            int ind=i%n;

            while(!st.empty() && nums[ind]>=st.top())
            {
                st.pop();
            }

            if(st.empty())
            {
                if(i<n)
                {
                    ans[i]=-1;
                }
            }
            else
            {
                if(i<n)
                {
                    ans[i]=st.top();
                }
            }

            st.push(nums[ind]);

        }
    return ans;
    }
};