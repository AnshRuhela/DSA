// User function Template for C++

class Solution {
  public:
    vector<int> minPartition(int N) {
        vector<int>coins{1,2,5,10,20,50,100,200,500,2000};
        int i=9;
        vector<int>ans;
        while(N>0 && i>=0) // start from back
        {
            if(coins[i]<=N)
            {
                N-=coins[i];
                ans.push_back(coins[i]);
            }
            else
            {
                i--;
            }
        }
        return ans;
    }
};