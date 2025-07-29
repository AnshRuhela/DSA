
struct Node
{
    Node*links[26];
    bool isPresent(char ch)
    {
        return links[ch-'a']!=NULL;
    }
    Node* getLink(char ch)
    {
        return links[ch-'a'];
    }
    void put(Node*n,char ch)
    {
        links[ch-'a']=n;
    }
};

class Trie
{
    private:
    Node*root;
    public:
    int count=1; // as empty string also considered.
    Trie()
    {
        root=new Node();
    }
    void insert(string word)
    {
        Node*node=root;
        for(int i=0;i<word.length();i++)
        {
            if(!node->isPresent(word[i]))
            {
                node->put(new Node(),word[i]);
                this->count++;
            }
            node=node->getLink(word[i]);
        }
    }
};

int countDistinctSubstrings(string &s)
{
    Trie t;
    int n=s.length();
    for(int i=0;i<n;i++)
    {
        string str="";
        for(int j=i;j<n;j++)
        {
            str.push_back(s[j]);
            t.insert(str);
        }
    }
    return t.count;
}