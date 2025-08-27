
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