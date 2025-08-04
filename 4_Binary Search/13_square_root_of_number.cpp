
// Function to find square root
// x: element to find square root
class Solution {
  public:
    int floorSqrt(int n) {
        int l=1,r=n;
        int ans;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(mid*mid==n) return mid;
            if(mid*mid<n)
            {
                ans=mid;
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