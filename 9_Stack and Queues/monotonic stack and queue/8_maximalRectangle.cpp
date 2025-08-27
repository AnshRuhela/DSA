class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int col=matrix[0].size();
        int row=matrix.size();
        vector<int>heights(col,0);
        int ans=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(matrix[i][j]=='1')
                {
                    heights[j]++;
                }
                else
                {
                    heights[j]=0;
                }
            }
            stack<int>st;
            int n=heights.size();
            int nse,pse;
            int area=0;
            for(int i=0;i<n;i++)
            {
                while(!st.empty() && heights[st.top()]>heights[i] )
                {
                    int elem=st.top();
                    st.pop();
                    int nse=i;
                    int pse=st.empty()?-1:st.top();
                    area=max(area,heights[elem]*(nse-pse-1));
                }
                    st.push(i);
            }
            while(!st.empty())
            {
                // these remaining elements don't have nse so their nse will be assumed at n
                int ind=st.top();
                st.pop();
                area=max(area,(heights[ind]*(n- (st.empty()?-1:st.top()) -1)));
            }
            ans=max(ans,area);
        }
        return ans;
    }
};