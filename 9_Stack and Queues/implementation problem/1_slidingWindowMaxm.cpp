
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;                               
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            while(!dq.empty() && nums[i]>nums[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>=k-1) // kam se kam 3 element traverse kar liye ho.
            {
                if((i-dq.front())+1>k) // kya dequeue me 3 se jayada element hai.
                { 
                    dq.pop_front();
                } 
                    ans.push_back(nums[dq.front()]);   
            }
        }
        return ans;
    }
};