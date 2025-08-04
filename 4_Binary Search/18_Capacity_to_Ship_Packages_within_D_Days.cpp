class Solution {
public:
    int findSum(vector<int>&weights)
    {
        int sum=0;
        for(auto it : weights)
        {
            sum+=it;
        }
        return sum;
    }
    int findDays(vector<int>&weights,int cap)
    {
        int day=1; // ek din to chahiye hi chahiye.
        int weight=0;
        for(int i=0;i<weights.size();i++)
        {
            if(weight+weights[i]>cap)
            {
                day++;
                weight=weights[i];
            }
            else
            {
                weight+=weights[i];
            }
        }
        return day;
    }
    int findMax(vector<int>&weights)
    {
        int maxi=INT_MIN;
        for(auto it : weights)
        {
            maxi=max(it,maxi);
        }
        return maxi;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int l=findMax(weights);
        int r=findSum(weights);
        int sum=findSum(weights);
        while(l<=r)
        {
            int mid=(l+r)/2;
            int day=findDays(weights,mid);
            if(day<=days)
            {
                r=mid-1; // capacity kam karo.
            }
            else if(day>days)
            {
                l=mid+1; // capacity jyada karo.
            }
        }
        return l;
    }
};