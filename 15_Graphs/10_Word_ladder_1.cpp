/*
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
*/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n=beginWord.length();

        unordered_set<string>st;
        for(int i=0;i<wordList.size();i++)
        {
         //   if(beginWord!=wordList[i])
            st.insert(wordList[i]);
        }
        if(st.find(endWord)==st.end()) return 0;
        // cout<<'h';
        queue<pair<string,int>>q;
        q.push({beginWord,1});  

        while(!q.empty())
        {
            pair<string,int>top=q.front();
            q.pop();
            if(top.first==endWord) 
            {
                 return top.second;
            }
            for(int i=0;i<n;i++)
            {
                    for(auto it : {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'})
                    {
                        string temp=top.first;
                        temp[i]=it;
                        if(st.find(temp)!=st.end())
                        {
                            q.push({temp,top.second+1});
                            st.erase(temp);
                        }
                    }
                // if(flag) break;
            }
        }
        return 0;
    }
};