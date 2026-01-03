class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
   
   int n1=m-1;
   int n2=n-1;
   int i=m+n-1;

   while(n1>=0 && n2>=0)
   {
       if(nums1[n1]>nums2[n2])
       {
           swap(nums1[n1],nums1[i]);
           n1--;
           i--;
       }
       else
       {
           swap(nums2[n2],nums1[i]);
           n2--;
           i--;
       }
   }

  
       while(n2>=0)
       {
           nums1[i]=nums2[n2];
           i--;
           n2--;
       }
   }
    

};