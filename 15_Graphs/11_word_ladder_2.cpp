

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