// Prim's Algorithm

#include <bits/stdc++.h>

using namespace std;

//on every road b/w two cities there is a bridge that can support a maximum weight {0,100]
//solve for the maximum weight that can be driven through a set of destination cities
//cities number 1 to c 1<=c<=10000
//at most 100 000 undriected roads
//starting at city 1 and city 1 is not a destination citiy
//can visit destination cities in any order, but must visit allocate
//modifying prim's algorithmn to compute the maximum spanning tree
//output the weight of the minimum edge in the tree


const int z = 0;//# of nodes in the graph
vector<int>dis(z, 0);
vector<vector<pair<int, int>>> adj(z );
vector<bool> vis(z , false); //visited vector
int n, m, d;
								/*
								adj list adj[u] ->{w,v}
								node u is adjacent to node v with a weight of w
								*/
priority_queue <pair<int,int>> pq;

void prim()
{
	
	int currNode = 1;
	int count = 0;
	while (count != n - 1)
	{
		vis[currNode] = true;//set curr node visited
		for (auto x : adj[currNode])//push every adjacent node into queue 
		{
			pq.push(x);
		}
		while (vis[pq.top().second] == 1)//while the node in the front of the queue is visited, pop it
		{
			pq.pop();
		}
		
		currNode = pq.top().second;//update currNode
		dis[currNode] = pq.top().first;
		pq.pop();//pop currNode
		count++;
	}
	
}
int main() {
	cin >> n >> m >> d;
	vis.resize(n+1, false);
	adj.resize(n+1);
	dis.resize(n + 1, 0);

	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w,v });
		adj[v].push_back({ w,u });
	}
	prim();
	int max = 100000;
	for (int i = 0; i < d; i++)
	{
		int a;
		cin >> a;
		if (dis[a] < max)
			max = dis[a];
	}
	cout << max;
}
