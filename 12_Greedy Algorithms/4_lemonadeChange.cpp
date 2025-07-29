class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0;
        int ten=0;
        int twen=0;
        int n=bills.size();
        for(int i=0;i<n;i++)
        {
            if(bills[i]==5)
            {
                five++;
            }
            else if(bills[i]==10) // agar 10 walal aaya then ek 5$ ka note to hona hi chahiye.
            {
                if(five>0)
                {
                    five--;
                    ten++;
                }
                else
                {
                    return false;
                }
            }
            else  // agar 20$ wala aaya then ya to ek 5 and ek 10 ka ho ya teen 5 ke ho.
            {
                if(ten>=1 && five>=1)
                {
                    five--;
                    ten--;
                }
                else if(five>=3)
                {
                    five-=3;
                }
                else
                {
                    return false;
                }
            }
        }   
        return true;
    }
};