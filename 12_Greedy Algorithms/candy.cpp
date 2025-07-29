class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        long long sum=1; // assuming pehle bache ke paas 1 candy hai.
        int i=1; // starting from 1.
        while(i<n)
        {
            if(ratings[i]==ratings[i-1]) // agar rating equal hai to 1 hi plus hoga.
            {
                sum+=1;
                i++;
                continue;
            }
            int peak=1; // taking peak =1 bcs ek bache ki starting minimum candy se karni padegi i.e. 1
            while(i<n && ratings[i]>ratings[i-1])  
            {
                peak+=1; // pehle peak plus kiya fir sum me add kiya kuki increase karte hue uski pehle wale se ek jyada deni padegi. 
                sum+=peak;
                i++;
            }
            int down=1;
            while(i<n && ratings[i]<ratings[i-1])
            {
                sum+=down; // pehle sum me plus kiya kuki down ki taraf jaa rahe hai yani next wale bache pe jyada(+1) candy hogi current wale se
                down+=1;
                i++;
            }
            if(peak<down) 
            {
                sum+=(down-peak);
            }
            
        }
        return sum;
    }
};