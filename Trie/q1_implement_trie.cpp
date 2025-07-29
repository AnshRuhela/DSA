struct Node
{
    Node *links[26];
    bool flag=false;
    bool containKey(char ch)
    {
        return links[ch-'a']!=NULL;
    }
    void putChar(char ch,Node*node)
    {
        links[ch-'a']=node;
    }
    Node* next(char ch)
    {
        return links[ch-'a'];
    }
};

class Trie {
public:
Node*root;
    Trie() {
         root=new Node();
    }
    
    void insert(string word) {
        Node *node=root;
        for(int i=0;i<word.length();i++)
        {
            if(!node->containKey(word[i]))
            {
                node->putChar(word[i],new Node());
            }
            node=node->next(word[i]);
        }
        node->flag=true;
    }
    
    bool search(string word) {
        Node *node=root;
        for(int i=0;i<word.length();i++)
        {
            if(!node->links[word[i]-'a'])
            {
                return false;
            }
            node=node->links[word[i]-'a'];
        }
        if(node->flag==true) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        Node * node=root;
        for(int i=0;i<prefix.length();i++)
        {
            if(!node->links[prefix[i]-'a'])
            {
                return false;
            }
            node=node->links[prefix[i]-'a'];
        }
        if(node!=NULL) return true;
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */