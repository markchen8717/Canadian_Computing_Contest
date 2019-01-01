#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//square grid system
//start at top left (1,1) 
//end at bottom right (n,n)
//(row,column)
//Q querries to (n,n)
//each coordinate has an elevation level
//If the elevation at either the beginning or the end of the step requires oxygen, a unit of oxygen is consumed by Alp during the step.
//cannot climb or descend more than 2 units of elevation in a single step.
//output total units of required oxygen if possible, else output not possible message
//bfs

int grid[30][30], Q, dis[30][30], n;

void bfs()
{
	int r[] = { -1,1,0,0 }; //left,right,up,down
	int c[] = { 0,0,-1,1 };
	memset(dis, -1, sizeof(dis));
	dis[1][1] = 0;
	queue<pair<int, int> > qq;
	qq.push({ 1,1 });
	while (!qq.empty())
	{
		auto u = qq.front();
		qq.pop();
		for (int i = 0; i < 4; i++)
		{
			int row = u.first;  
			int col = u.second;
			row += r[i]; col += c[i];
			if (row >= 1 && row <= n && col >= 1 && col <= n)
			{
				if (abs(grid[row][col] - grid[u.first][u.second]) > 2)
					continue;
				int cost = (grid[row][col] > grid[1][1] || grid[u.first][u.second] > grid[1][1]) ? dis[u.first][u.second] + 1 : dis[u.first][u.second];
				if (dis[row][col] == -1 || dis[row][col] > cost)
					dis[row][col] = cost, qq.push({ row,col });
			}
		}
	}
}

int main() {
	cin >> Q;
	while (Q--)
	{

		cin >> n;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				cin >> grid[i][j];
		bfs();
		if (dis[n][n] != -1)
			cout << dis[n][n];
		else
			cout << "CANNOT MAKE THE TRIP";
		cout << "\n\n";
	}
}
