/*
A new alien language uses the English alphabet, but the order of letters is unknown. You are given a list of words[] from the alien language’s dictionary, where the words are claimed to be sorted lexicographically according to the language’s rules.

Your task is to determine the correct order of letters in this alien language based on the given words. If the order is valid, return a string containing the unique letters in lexicographically increasing order as per the new language's rules. If there are multiple valid orders, return any one of them.

However, if the given arrangement of words is inconsistent with any possible letter ordering, return an empty string ("").

A string a is lexicographically smaller than a string b if, at the first position where they differ, the character in a appears earlier in the alien language than the corresponding character in b. If all characters in the shorter word match the beginning of the longer word, the shorter word is considered smaller.

Note: Your implementation will be tested using a driver code. It will print true if your returned order correctly follows the alien language’s lexicographic rules; otherwise, it will print false.

Examples:

Input: words[] = ["baa", "abcd", "abca", "cab", "cad"]
Output: true
Explanation: A possible corrct order of letters in the alien dictionary is "bdac".
The pair "baa" and "abcd" suggests 'b' appears before 'a' in the alien dictionary.
The pair "abcd" and "abca" suggests 'd' appears before 'a' in the alien dictionary.
The pair "abca" and "cab" suggests 'a' appears before 'c' in the alien dictionary.
The pair "cab" and "cad" suggests 'b' appears before 'd' in the alien dictionary.
So, 'b' → 'd' → 'a' → 'c' is a valid ordering.
Input: words[] = ["caa", "aaa", "aab"]
Output: true
Explanation: A possible corrct order of letters in the alien dictionary is "cab".
The pair "caa" and "aaa" suggests 'c' appears before 'a'.
The pair "aaa" and "aab" suggests 'a' appear before 'b' in the alien dictionary. 
So, 'c' → 'a' → 'b' is a valid ordering.
Input: words[] = ["ab", "cd", "ef", "ad"]
Output: ""
Explanation: No valid ordering of letters is possible.
The pair "ab" and "ef" suggests "a" appears before "e".
The pair "ef" and "ad" suggests "e" appears before "a", which contradicts the ordering rules.
*/
class Solution {
  public:
    string topoSort( unordered_map<char,vector<char>>&adj,vector<int>&isPresent)
    {
        vector<int>indegree(26,0);
        for(auto it : adj)
        {
            for(auto i : it.second)
            {
                indegree[i-'a']++;
            }
        }
        string topo="";
        queue<char>q;
        for(int i=0;i<26;i++)
        {
            if(indegree[i]==0 && isPresent[i]==1)
            {
                q.push(i+'a'); // convert kiya char me
                
            }
        }
        while(!q.empty())
        {
            char front=q.front();
            q.pop();
            topo+=front;
            for(auto it : adj[front])
            {
                indegree[it-'a']--;
                if(indegree[it-'a']==0)
                {
                    q.push(it);
                }
            }
        }
        return topo;
    }
    string findOrder(vector<string> &words) {
        unordered_map<char,vector<char>>adj;
        int n=words.size();
        vector<int>isPresent(26,0);
        int nodeCount=0;
        for(auto it : words)
        {
            for(auto i : it)
            {
                if(isPresent[i-'a']!=1) // we took a present array so that ye pta chal sake ki 26 char me se konsi konsi node graph me hai.
                {
                    isPresent[i-'a']=1;
                    nodeCount++;
                }
            }
        }
        for(int i=0;i<n-1;i++)
        {
            int len1=words[i].length();
            int len2=words[i+1].length();
            int j=0;
            while(j<len1 && j<len2)
            {
                if(words[i][j]==words[i+1][j]) // agar equal hi aage chalo
                {
                    j++;
                }
                else
                {
                    adj[words[i][j]].push_back(words[i+1][j]); // agar equal nahi hai uski edge bnado graph me
                    break;
                }
            }
            if(j==len1 || j==len2) // agar koi bhi string khatam hui iska matlab starting me dono string same this
            {
                if(len1>len2) return ""; // agar pehli wali string badi aai iska matlab order glat hai.
            }
        }
        string topo="";
        topo=topoSort(adj,isPresent);
        
        if(topo.length()!=nodeCount) // means cycle is present and agar cycle present hai means how can a>a menas ek char apne aap se hi bda hai
        {
            return "";
        }
        return topo;
    }
};