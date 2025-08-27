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