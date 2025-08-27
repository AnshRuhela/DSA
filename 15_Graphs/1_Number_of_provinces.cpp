class Solution {
public:
    int findParent(vector<int>&parent,int u)
    {
        if(parent[u]==u)
        return u;
        return findParent(parent,parent[u]);
    }

    void union1(int u,int v,vector<int>&parent,vector<int>&rank)
    {
        int p1=findParent(parent,u);
        int p2=findParent(parent,v);
        if(p1!=p2)
        {
            if(rank[p1]>rank[p2])
            {
                parent[p2]=p1;
            }
            else if(rank[p1]<rank[p2])
            {
                parent[p1]=p2;
            }
            else
            {
                parent[p2]=p1;
                rank[p1]++;
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>>edges;
        int n=isConnected.size();
        int m=isConnected[0].size();
        vector<int>parent(n+1,-1);
        for(int i=1;i<n+1;i++)
        {
            parent[i]=i;
        }

        vector<int>rank(n+1,0);

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(isConnected[i-1][j-1]==1)
                {
                    union1(i,j,parent,rank);
                }
            }
        }

        int count=0;
        for(int i=1;i<=n;i++)
        {
            if(parent[i]==i)
                count++;
        }

        return count;

    }
};