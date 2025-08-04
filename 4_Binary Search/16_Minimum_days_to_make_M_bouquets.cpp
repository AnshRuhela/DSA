class Solution {
public:
    int findMin(vector<int>&bloomDay)
    {
        int mini=INT_MAX;
        for(auto it : bloomDay)
        {
            mini=min(mini,it);
        }
        return mini;
    }
    int findMax(vector<int>&bloomDay)
    {
        int maxi=INT_MIN;
        for(auto it : bloomDay)
        {
            maxi=max(maxi,it);
        }
        return maxi;
    }

    int find(vector<int>&bloomDay,int day,int k)
    {
        int bouq=0;
        int count=0;
        for(auto it : bloomDay)
        {
            if(day>=it)
            {
                count++;
            }
            else
            {
                bouq+=count/k;
                count=0;
            }
        }
        bouq+=count/k;
        cout<<bouq<<endl;
        return bouq;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        int l=findMin(bloomDay);
        int r=findMax(bloomDay);
        int ans=-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            int bouq=find(bloomDay,mid,k);
            if(bouq>=m)
            {
                r=mid-1;
                ans=mid;
            }
            else if(bouq<m)
            {
                l=mid+1;
            }
        }
        return ans;
    }
};