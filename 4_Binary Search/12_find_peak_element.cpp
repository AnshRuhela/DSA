class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n=arr.size();
        if(n==1) return 0;
        if(arr[0]>arr[1]) return 0;
        if(arr[n-1]>arr[n-2]) return n-1;

        int l=1,r=n-2;
        int ans;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
            {
                return mid;
            }
            else if(arr[mid]>arr[mid-1])
            {
                l=mid+1;
            }
            else // else if(arr[mid]>arr[mid+1]) will not work for multiple peak.
            {
                r=mid-1;
            }
        }
        return -1; // summy return this will never run.
    }
};
