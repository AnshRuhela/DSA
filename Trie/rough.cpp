#include<iostream>
using namespace std;

struct Node
{
    Node*links[26];
    bool flag=false;

    bool isContain(char ch)
    {
        return links[ch-'a']!=NULL;
    }

    void putChar(char ch, Node*node)
    {
        links[ch-'a']=node;
    }

    Node*next(char ch)
    {
        return links[ch-'a'];
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
            if(!node->isContain(word[i]))
            {
                node->putChar(word[i],new Node());
            }
            node=node->next(word[i]);
        }
        node->flag=true;
    }


    bool isPresent(string word)
    {
        Node*node=root;
        for(int i=0;i<word.length();i++)
        {
            if(!node->isContain(word[i]))
            {
                return false;
            }
            node=node->next(word[i]);
        }
        if(node->flag==true) return true;
        return false;
    }


    bool startWith(string word)
    {
        Node*node=root;
        for(int i=0;i<word.length();i++)
        {
            if(!node->isContain(word[i]))
            {
                return false;
            }
            node=node->next(word[i]);
        }
        if(node==NULL) return false;
        return true;
    }



};

int main()
{

    
    return 0;
}