#include <bits/stdc++.h> 
struct Node{
    Node* links[26];
    int ew = 0;
    int cp = 0;

    bool containsKey(char ch){
        return (links[ch - 'a']!=NULL);
    }
    void put(Node* node , char ch){
        links[ch - 'a'] = node;
    }

    Node* get(char ch){
        return links[ch - 'a'];
    }
};
class Trie{

    private:
    Node* root;
    public:

    Trie(){
        // Write your code here.
        root = new Node();
    }

    void insert(string &word){
        // Write your code here.
        Node* node = root;
        for(int i = 0; i<word.length(); i++){
            if(!node->containsKey(word[i])){
                node->put(new Node(), word[i]);
            }
            node = node->get(word[i]);
            node->cp++;
        }
        node->ew++;
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node* node = root;
        for(int i = 0; i<word.length(); i++){
            if(!node->containsKey(word[i])){
                return 0;
            }
            node = node->get(word[i]);
        }
        return node->ew;
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node* node = root;
        for(int i = 0; i<word.length(); i++){
            if(!node->containsKey(word[i])){
                return 0;
            }
            node = node->get(word[i]);
        }
        return node->cp;
    }

    void erase(string &word){
        // Write your code here.
        Node* node = root;
        for(int i = 0; i<word.length(); i++){
            node = node->get(word[i]);
            node->cp--;
        }
        node->ew--;
    }
};