class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        int n=num.length();
        if(k>=n) return "0";
        int flag=0;
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            {
                st.push(num[i]);
            }
            else
            {
                while(!st.empty() && st.top()>num[i])
                {
                    st.pop();
                    k--;
                    if(k==0)
                    {
                        while(i<n)
                        {
                            st.push(num[i]);
                            i++;
                        }
                        flag=1;
                    break;
                    }
                }
                if(flag==1) break;
                if(st.empty() && num[i]=='0')
                {
                    continue;
                }
                else
                {
                    st.push(num[i]);
                }
            }
        }    
        string str;
        while(!st.empty())
        {
            str+=(st.top());
            st.pop();
        }
        for(int i=str.length()-1;i>=0;i--)
        {
            if(str[i]=='0'){
                str.pop_back();
            }
            else break;
        }



        reverse(str.begin(),str.end());
        for(int i=str.length()-1;i>=0;i--)
        {
            if(k>0)
            {
                str.pop_back();
                k--;
            }
        }
        if(str.length()==0) return "0";
        else return str;
    }
};