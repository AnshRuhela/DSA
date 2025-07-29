class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        // code here
         // code here
        int n = mat.size();
        int i = 0;
        int j = n-1;

        while(i<j){
            if(mat[i][j]==1){
                i++;
            }
            else if(mat[j][i]==1){
                j--;
            }
            else{
                i++;
                j--;
            }
        }
            for(int k = 0; k<n; k++){
                if(k!=i){
                    if(mat[i][k]==1 || mat[k][i]==0) return -1;
                }
            }
            return i;
    }
};