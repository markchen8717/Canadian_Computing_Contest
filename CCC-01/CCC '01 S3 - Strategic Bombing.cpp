



#include <bits/stdc++.h>
#define obforall(i,a) for( const auto& i : a)
#define modforall(i,a) for (auto&& i : a)

using namespace std;
//point A B C D E.. at most 26 points are linked by a network of roads
//identify a SINGLE road to take out in order to cut off all traffic b/w A and B
//input
	//Each line of input indentifies a pair of points connected by a road
	//End of input is **
	//All roads are two way
	//At most one road b/w any two points
//output
	//identify all SINGLE roads that can halt all traffic b/w A and B once out of order
	//list the roads, one per line
	//print "There are 0 disconnecting roads." if no such raod
	//print "There are n disconnecting roads." where n is the number of such raods
//Take in all paths with adjacency matrix
//For each path, take it out of the matrix, and do bfs on the graph to check
	//if a and b is connected
//remeber to restore the graph each time

bool adj[26][26];
vector<string> i;
int dis[26],cnt;

void bfs()
{
	memset(dis,-1,sizeof(dis));
	queue<int> q;
	q.push(0);
	dis[0]=0;
	while(!q.empty())
	{
		int cur = q.front();
		q.pop();
		for(int i = 0 ; i <26;i++)
		{
			if(adj[cur][i] && (dis[i] == -1 || dis[i] > dis[cur]+1))
			{dis[i] = dis[cur]+1;q.push(i);}
		}
	}
	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string input;
	do{
		cin>>input;
		i.push_back(input);
		adj[input[0]-65][input[1]-65]=1;
		adj[input[1]-65][input[0]-65]=1;
	}while(input!="**");
	for(auto x:i)
	{
		adj[x[0]-65][x[1]-65]=0;
		adj[x[1]-65][x[0]-65]=0;
		bfs();
		if(dis[1] == -1)
		{	cout<<x<<"\n"; cnt++;}
		adj[x[0]-65][x[1]-65]=1;
		adj[x[1]-65][x[0]-65]=1;
	}
	if(!cnt)
		cout<<"There are 0 disconnecting roads.";
	else
		cout<<"There are "<<cnt<<" disconnecting roads.";
	
	return 0;
}
