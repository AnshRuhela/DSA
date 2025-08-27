class StockSpanner {
public:
        stack<pair<int,int>>st;
        int ind;
    StockSpanner() {
        ind=-1;
    }
    
    int next(int price) {
        ind++;
        while(!st.empty() && price>=st.top().second)
        {
            st.pop();
        }

        int ans;
        if(st.empty())
        {
            ans= ind+1; // means abhi tak ka sabse bda element aaya hai.
        }
        else
        {
            ans= ind-st.top().first; 
        }
        st.push({ind,price});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */