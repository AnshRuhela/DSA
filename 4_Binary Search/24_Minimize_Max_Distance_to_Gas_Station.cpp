class Solution {
  public:
    double findSmallestMaxDist(vector<int> &stations, int k) {
        int n=stations.size();
        priority_queue<pair<double,int>>pq; // pehle distance, phir index
        for(int i=0;i<n-1;i++)
        {
            pq.push({stations[i+1]-stations[i],i});
        }
        
        vector<int>sectors(n-1,0);
        for(int i=0;i<k;i++)
        {
            auto top=pq.top();
            pq.pop();
            double dist=top.first;
            int ind=top.second;
            double newDist=stations[ind+1]-stations[ind];
            sectors[ind]++;
            newDist=newDist/(double)(sectors[ind]+1);
            pq.push({newDist,ind});
        }
        return pq.top().first;
    } // this code is 100% correct bas submit nahi ho rha.
};