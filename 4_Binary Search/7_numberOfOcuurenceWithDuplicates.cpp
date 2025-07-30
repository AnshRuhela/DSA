
class Solution {
  public:
    void findLeft(vector<int>&arr,int target,int l,int r,int &LeftInd)
    {
        if(l<=r)
        {
            int mid=(l+r)/2;
            if(arr[mid]==target)
            {
                LeftInd=mid;
                findLeft(arr,target,l,mid-1,LeftInd);
            }
            else if(target<arr[mid])
            {
                findLeft(arr,target,l,mid-1,LeftInd);
            }
            else
            {
                findLeft(arr,target,mid+1,r,LeftInd);
            }
        }
    }
    void findRight(vector<int>&arr,int target,int l,int r,int &rightInd)
    {
        if(l<=r)
        {
            int mid=(l+r)/2;
            if(arr[mid]==target)
            {
                rightInd=mid;
                findRight(arr,target,mid+1,r,rightInd);
            }
            else if(target<arr[mid])
            {
                findRight(arr,target,l,mid-1,rightInd);
            }
            else
            {
                findRight(arr,target,mid+1,r,rightInd);
            }
        }
    }
    int countFreq(vector<int>& arr, int target) {
        int n=arr.size();
        int leftInd=-1,rightInd=-1;
        findLeft(arr,target,0,n-1,leftInd); // applying binary search
        findRight(arr,target,0,n-1,rightInd);
        if(rightInd<0) return 0;
        return rightInd-leftInd+1;
    }
};
