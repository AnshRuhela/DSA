class Solution {
public:
    double findHours(vector<int>&piles,int mid)
    {
        double hours=0;
        for(auto i : piles)
        {
           hours += ceil((double)i / mid);

        }
        return hours;
    }
    int maxElem(vector<int>&piles )
    {
        int maxi=INT_MIN;
        for(auto it : piles)
        {
            maxi=max(maxi,it);
        }
        return maxi;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int l=1,r=maxElem(piles);
        int ans;
        while(l<=r)
        {
            int mid=(l+r)/2;
            double hours=findHours(piles,mid);
            if(hours<=h)
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
};