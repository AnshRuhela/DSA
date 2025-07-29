class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        stack<int>st;
        int n2=nums2.size();
        unordered_map<int,int>nge; // nge means next greater element
        for(int i=n2-1;i>=0;i--)
        {
            while(!st.empty() && nums2[i]>=st.top())
            {
                st.pop();
            }

            if(st.empty())
            {
                nge[nums2[i]]=-1;
            }
            else
            {
                nge[nums2[i]]=st.top();
            }
            st.push(nums2[i]);
        }
        vector<int>ans;
        for(int i=0;i<nums1.size();i++)
        {
            ans.push_back(nge[nums1[i]]);
        }
        return ans;
    }
};