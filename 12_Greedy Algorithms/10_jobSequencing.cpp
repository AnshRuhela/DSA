class Solution {
    
  public:
  
    static bool comp(pair<int,int>&a,pair<int,int>&b)
    {
        return a.second>b.second;
    }
  
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n=deadline.size();
        int maxi=INT_MIN;
        vector<pair<int,int>>comb;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,deadline[i]);
        }
        vector<int>arr(maxi+1,-1);
        for(int i=0;i<n;i++)
        {
            comb.push_back({deadline[i],profit[i]});
        }
        sort(comb.begin(),comb.end(),comp);
        int count=0;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            
            int j=comb[i].first;
            while(j>=1 && arr[j]!=-1) // delay jyada se jyada.
            {
                j--;
            }
            if(j>=1) // agar slot empty hai to vha ek job kar sakte hai but agar j>=1 nahi hua means vo job skip karni padegi.
            {
                arr[j]=1;
                count++;
                sum+=comb[i].second;
            }
        }
            return {count,sum};
    }
};


