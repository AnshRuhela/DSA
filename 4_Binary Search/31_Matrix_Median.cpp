
// User function template for C++

class Solution {
  public:
    int findMin(vector<vector<int>>&mat,int r,int c)
    {
        int mini=INT_MAX;
        for(int i=0;i<r;i++)
        {
            mini=min(mini,mat[i][0]);
        }
        return mini;
    }
    int findMax(vector<vector<int>>&mat,int r, int c)
    {
        int maxi=INT_MIN;
        for(int i=0;i<r;i++)
        {
            maxi=max(maxi,mat[i][c-1]);
        }
        return maxi;
    }
    int upperBound(vector<int>arr,int r,int c ,int no)
    {
        int l=0,h=arr.size()-1;
        int ind=-1;
        while(l<=h)
        {
            int mid=(l+h)/2;
            if(arr[mid]==no)
            {
                l=mid+1;
            }
            else if(arr[mid]>no)
            {
                h=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return l;
    }
    int howManyLessEqual(vector<vector<int>>&mat,int r,int c,int mid)
    {
        int count=0;
        for(int i=0;i<r;i++)
        {
             count += upperBound(mat[i],i,c,mid);
        }
        return count;
    }
    int median(vector<vector<int>> &mat) {
        int r=mat.size();
        int c=mat[0].size();
        int low=findMin(mat,r,c);
        int high=findMax(mat,r,c);
        int left=(r*c)/2;
        while(low<=high)
        {
            int mid=(low+high)/2;
            int no=howManyLessEqual(mat,r,c,mid);
            if(no>left)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return low;
    }
};
