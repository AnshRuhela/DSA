struct Node
{
    Node*links[2];
    bool isContain(int bit)
    {
        return links[bit]!=NULL;
    }
    void put(int bit,Node*n)
    {
        links[bit]=n;
    }
    Node* get(int bit)
    {
        return links[bit];
    }
};
class Trie
{
    private:
    Node*root;
    public:
    Trie()
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
    int getMax(int x)
    {
        Node*node=root;
        int ans=0;
        for(int i=31;i>=0;i--)
        {
            int bit=(x>>i)&1;
            if(node->isContain(!bit)) // ulti bit check krna
            {
                ans=ans|1<<i; // or we can write --->ans=ans+(pow(2,i));
                node=node->links[!bit];
            }
            else
            {
                node=node->links[bit];
            }
        }
        return ans;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie t;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            t.insert(nums[i]);
        }
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            if (maxi<t.getMax(nums[i]))
            {
                maxi=t.getMax(nums[i]);
            }
        }
        return maxi;
    }
};