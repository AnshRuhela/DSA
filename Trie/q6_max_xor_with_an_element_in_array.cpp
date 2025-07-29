
struct Node
{
    Node*links[2];
    bool isContain(int bit)
    {
        return links[bit]!=NULL;
    }
    Node* get(int bit)
    {
        return links[bit];
    }
    void put(int bit,Node*node)
    {
        links[bit]=node;
    }
};

class Tree
{
    private:
    Node*root;
    public:
    Tree()
    {
        root=new Node();
    }
    void insert(int num)
    {
        Node*node=root;
        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i)&1;
            if(!node->isContain(bit))
            {
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }

    int getMax(int num)
    {
        int ans=0;
        Node*node=root;
        if(node->links[0]==NULL && node->links[1]==NULL) return -1; // 
        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i)&1;
            if(node->isContain(!bit))
            {
                ans=ans|1<<i;
                node=node->get(!bit);
            }
            else
            {
                node=node->get(bit);
            }
        }
        return ans;
    }

};

class Solution {
public:
    static bool comp(pair<pair<int,int>,int>&a,pair<pair<int,int>,int>&b)
    {
        return a.first.second<b.first.second;
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int len=nums.size();
        int m=queries.size();
        int n=queries[0].size();
        Tree t;
        vector<int>ans(m);
        vector<pair<pair<int,int>,int>>arr;
        sort(nums.begin(),nums.end());
        for(int i=0;i<m;i++)
        {
            int u=queries[i][0];
            int v=queries[i][1];
            arr.push_back({{u,v},i});
        }
        int temp=0;
        sort(arr.begin(),arr.end(),comp); 
        int j=0;
        for(int i=0;i<m;i++)
        {
            while(j<len && nums[j]<=arr[i].first.second)
            {
                t.insert(nums[j]);
                j++;
            }
            temp=t.getMax(arr[i].first.first);
            ans[arr[i].second]=temp;
        }
        return ans;
    }
};