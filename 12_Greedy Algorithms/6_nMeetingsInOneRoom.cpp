
/*
    why we sorted according to end time ?
    bcs we would like to choose those meetings which are ending fast.
    consider case [[1-6],[4-5],[5-6]] in this case we want to perform maximum no. of meetings so we will choose 2nd and 3rd not 1st 
    bcs even though [1-4] wala time waste ho rha hai par meeting to jyada ho rhi hai. 
*/

class Solution {
  public:
    
    static bool comp(pair<int,int>&a,pair<int,int>&b)
    {
        return a.second<b.second;
    }
  
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n=start.size();
        vector<pair<int,int>>meetings;
        for(int i=0;i<n;i++)
        {
            meetings.push_back({start[i],end[i]});
        }
        sort(meetings.begin(),meetings.end(),comp);
        int count=1,endTime=meetings[0].second;
        for(int i=1;i<n;i++)
        {
            if(endTime<meetings[i].first)
            {
                count++;
                endTime=meetings[i].second;
            }
        }
        return count;
    }
    
}; 