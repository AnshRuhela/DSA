class Solution {
public:
    int findMaxInCol(vector<vector<int>>&mat,int col,int r,int c)
    {
        int maxi=INT_MIN;
        int row;
        for(int i=0;i<r;i++)
        {
            if(maxi<mat[i][col])
            {
                maxi=mat[i][col];
                row=i;
            }
        }
        return row;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int r=mat.size();
        int c=mat[0].size();
        int l=0,h=c-1;
        while(l<=h)
        {
            int mid=(l+h)/2;
            int row=findMaxInCol(mat,mid,r,c); 
            int left=mid-1>=0?mat[row][mid-1]:-1;
            int right=mid+1<c?mat[row][mid+1]:-1;
            if(mat[row][mid]>left && mat[row][mid]>right)
            {
                return {row,mid};
            }
            else if(mat[row][mid]<left)
            {
                h=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return {-1,-1};
    }
};