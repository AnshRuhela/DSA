#include<bits/stdc++.h>
using namespace std;
class Graph{
    public:
    unordered_map<int,list<pair<int,int>>> adj;

    void addEdge(int u , int v , int weight){
        pair<int,int> p;
        p = make_pair(v,weight);

        adj[u].push_back(p);
    }

    void Print(){
        for(auto i : adj){
            cout<<i.first<<"->";
            for(auto j : i.second){
                cout<<"["<<j.first<<","<<j.second<<"]";
            }cout<<endl;
        }
    }

    void topologicalSort(int node ,  stack<int> &st , unordered_map<int,bool> &visited){
        visited[node] = true;

        for(auto i : adj[node]){
            if(!visited[i.first]){
                topologicalSort(i.first,st,visited);
            }
        }
        st.push(node);
    }

    void getShortPath(int src , stack<int> &st , vector<int> &dist){
        dist[src] = 0;

        while(!st.empty()){
        int top = st.top();
        st.pop();

            if(dist[top]!=INT_MAX){
                for(auto i : adj[top]){
                    if(dist[top] + i.second < dist[i.first]){
                        dist[i.first] = dist[top] + i.second;
                    }
                }
            }
        }

    }

};
int main(){
    Graph g;
    g.addEdge(0,1,5);
    g.addEdge(0,2,3);
    g.addEdge(1,2,2);
    g.addEdge(1,3,6);
    g.addEdge(2,3,7);
    g.addEdge(2,4,4);
    g.addEdge(2,5,2);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,-2);

    g.Print();


    unordered_map<int,bool> visited;
    stack<int> st;
    int n = 6;
    for(int i = 0; i<n; i++){
        if(!visited[i]){
    g.topologicalSort(i,st,visited);

        }
    }

    vector<int> dist(n);
    int src = 1;
    for(int i = 0; i<n; i++){
        dist[i] = INT_MAX;
    }

    g.getShortPath(src,st,dist);

    for(int i = 0; i<dist.size(); i++){
        cout<<dist[i]<<" ";
    }

    return 0;
}