#include<unordered_map>
#include<queue>
#include<vector>
#include<list>

vector<int> topologicalSort(vector<pair<int,int>>& edges, int N, int M)
{
	
	unordered_map<int,list<int>>adj;

	for(int i=0;i<edges.size();i++)
	{
		int u=edges[i].first;
		int v=edges[i].second;

		adj[u].push_back(v);
	}


	vector<int> indegree(N);

	for(auto i:adj)
	{
		for(auto j:i.second)
		{
			indegree[j]++;
		}
	}

	queue<int> q;

	for(int i=1;i<=N;i++)
	{
		if(indegree[i]==0)
		{
			q.push(i);
		}
	}


	vector<int> ans;

	while(!q.empty())
	{
		int front=q.front();
		q.pop();

		ans.push_back(front);

		for(auto neighbour:adj[front])
		{
			indegree[neighbour]--;

			if(indegree[neighbour]==0)
			{
				q.push(neighbour);
			}
		}
	}
return  ans;
} 
a