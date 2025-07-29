class Solution {
public:

    vector<int>findNse(vector<int>arr)
    {
        stack<int>st;
        int n=arr.size();
        vector<int>nse(n);
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && arr[i]<=arr[st.top()])
            {
                st.pop();
            }

            if(st.empty())
            {
                nse[i]=n;
            }
            else
            {
                nse[i]=st.top();
            }
            st.push(i);
        }
        return nse;
    }


    vector<int>findPsee(vector<int>arr)
    {
        int n=arr.size();
        vector<int>pse(n);
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[i]<arr[st.top()])
            {
                st.pop();
            }

            if(st.empty())
            {
                pse[i]=-1;
            }
            else
            {
                pse[i]=st.top();
            }
            st.push(i);
        }
        return pse;
    }


    int sumSubarrayMins(vector<int>& arr) {
        long long sum=0;
        long long mod=1e9+7;
        vector<int>nse;
        vector<int>pse;
        nse=findNse(arr);
        pse=findPsee(arr);
        long long n=arr.size();
        for(int i=0;i<n;i++)
        {
            sum=(sum+(((i-pse[i])*(nse[i]-i))%mod)*arr[i])%mod;
        }
    return sum;
    }
};