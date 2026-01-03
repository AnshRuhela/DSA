/*
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
Explanation: There are 2 shortest transformation sequences:
"hit" -> "hot" -> "dot" -> "dog" -> "cog"
"hit" -> "hot" -> "lot" -> "log" -> "cog"
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: []
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
*/

// this code is giving TLE.


class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        set<string>st;
        for(auto it : wordList)
        {
            st.insert(it);
        }
        int n=wordList.size();
        queue<vector<string>>q;
        int level=0;
        q.push({beginWord});
        vector<string>usedOnLevels;// level pe kon konse words use ho chuke hai.
        usedOnLevels.push_back(beginWord);
        vector<vector<string>>ans;
        while(!q.empty())
        {
            auto top=q.front();
            q.pop();
            if(top.back()==endWord)
            {
                ans.push_back(top);
            }
            if(top.size()>level)
            {
                for(auto it : usedOnLevels) // removing all the words that has been used on the current level as we don't need them anymore
                {
                    st.erase(it);
                }
                level++;
            }
            string s=top.back();
            for(int i=0;i<s.length();i++)
            {
                string str=s;
                for(char j='a';j<='z';j++)
                {
                    str[i]=j;
                    if(st.find(str)!=st.end())
                    {
                        top.push_back(str);
                        usedOnLevels.push_back(str);
                        q.push(top);
                        top.pop_back();
                    }
                }
            }
        }
        return ans;
    }
};