
// User function Template for C++

class Solution {
  public:
    bool check(vector<int>&stalls,int mid,int k)
    {
        int count=1;
        int lastInd=0; // pehli cow to 0 ind pe hi place hogi.
        for(int i=1;i<stalls.size();i++)
        {
            if(stalls[i]-stalls[lastInd]>=mid) // agar mid distance se zyada hai to cow ko place kar sakte hain.
            {
                count++;
                lastInd=i;
            }
        }
        if(count>=k) // agar count of cows jo place ki hain wo k se zyada ya barabar hai to return true. it means we can place cows with at least mid distance apart.
        {
            return true;
        }
        return false; // means mid distance pe hum k se kum hi cows place kar paye hain.
    }
        
    int aggressiveCows(vector<int> &stalls, int k) {
        int n=stalls.size();
        int l=1;
        sort(stalls.begin(),stalls.end());
        int r=stalls[n-1]-stalls[0];
        int ans;
        while(l<=r)
        {
            int mid=(l+r)/2;
            bool isPossible=check(stalls,mid,k);
            if(isPossible)
            {
                ans=mid; // this can be our answer but we need to maximize the answer.
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return ans;
    }
};