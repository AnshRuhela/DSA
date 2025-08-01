class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        int n=intervals.size();
        
        int i=0;
        while(i<n && intervals[i][1]<newInterval[0]) // pehle check kro left wale part ke liye joki overlap nahi ho raha hai.
        {
            ans.push_back(intervals[i]);
            i++;
        }
        while(i<n && intervals[i][0]<=newInterval[1]) // fir jo overlap ho raha hai uske liye loop.
        {
            newInterval[0]=min(newInterval[0],intervals[i][0]);
            newInterval[1]=max(newInterval[1],intervals[i][1]);
            i++;
        }
        ans.push_back(newInterval);
        while(i<n) // last wale jo bache joki overlap nahi ho rahe.
        {
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};