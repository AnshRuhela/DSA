class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size();
        int c=matrix[0].size();

        int l=0,h=(r*c)-1;
        while(l<=h)
        {
            int mid=(l+h)/2;
            int row=mid/c;
            int col=mid%c;
            if(matrix[row][col]==target)
            {
                return true;
            }
            else if(matrix[row][col]<target)
            {
                l=mid+1;
            }
            else
            {
                h=mid-1;
            }
        }
    return false;
    }
};