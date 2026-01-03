#include <bits/stdc++.h> 

struct Node
{
    Node*links[26];
    bool flag=false;
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
    public:
    Node*root;
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
            }
            node=node->getLink(word[i]);
        }
        node->flag=true;
    }

    bool getAns(string str)
    {
        Node*node=root;
        for(int i=0;i<str.length();i++)
        {
            node=node->getLink(str[i]);
            if(node->flag==false)
            {
                return false;
            }
        }
        return true;
    }
};

string completeString(int n, vector<string> &a){
    Trie t;
    for(int i=0;i<n;i++)
    {
        t.insert(a[i]);
    }    
    string ans="";
    for(int i=0;i<n;i++)
    {
        bool check=t.getAns(a[i]);
        if(check==true)
        {
            if(ans.length()<a[i].length() || (ans.length()==a[i].length() && ans>a[i]))
            {
                ans=a[i];
            }
        }
    }

    if(ans=="")
    {
        return "None";
    }
    return ans;
}


