class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        int n=dep.size();
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        int i=0,j=0;
        int  count=0,maxcount=0;
        while(i<n && j<n) // as time passes we check kitni train aa chuki hai and kisi particular time pe kitni train maxim ruk rahi hai.
        {
            if(arr[i]<=dep[j])
            {
                count++;
                i++;
            }
            else
            {
                count--;
                j++;
            }
            maxcount=max(count,maxcount);
        }
        return maxcount;
    }
};
