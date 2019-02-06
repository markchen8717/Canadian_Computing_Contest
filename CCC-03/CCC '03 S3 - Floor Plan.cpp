#include <bits/stdc++.h>


using namespace std;

//'I' for walls and '.' for room space, occupying one square metre
//Door ways are not shown
//given floor plan and supply of hardwood flooring
	//determine how many rooms will have flooring installed
	//start installing the floor in the decending order of room size
	//stop when you do not have enough wood for next room
//output the numver of rooms that can have hardwood installed
	//how many square metres of flooring are left over
//Traverse the floor map by rows and columns and use bfs to find space of each room

	
	bool vis[30][30];
char tomb[30][30];
vector<int> floors;
bool mda(int i, int j)
{
	return i>j;
}

int main()
{
	int n, r, c;
	cin >> n >> r >> c;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> tomb[i][j];

	pair<int, int> room = { -1,-1 };

	
	do{
	room = { -1,-1 };
	for (int i = 0; i < r; i++) {
		bool out = 0;
		for (int j = 0; j < c; j++)
		{
			if (out)
				break;
			if (tomb[i][j] == '.') {
				room = { i,j };
				out = 1;
			}
		}
		if (out)
			break;
	}
	
	if(room.first == -1 && room.second == -1)
	{break;}
		memset(vis, false, sizeof(vis));
		int cnt = 0;
		queue<pair<int, int>> q;
		q.push({ room.first,room.second });
		tomb[room.first][room.second] = 'I';
		cnt++;
		vis[room.first][room.second] = 1;
		while (!q.empty())
		{
			auto top = q.front();
			q.pop();
			int rd[] = { -1,1,0,0 };
			int cd[] = { 0,0,-1,1 };
			for (int i = 0; i < 4; i++)
			{
				int nr = top.first + rd[i];
				int nc = top.second + cd[i];
				if (nr >= 0 && nc >= 0 && nr < r && nc < c && tomb[nr][nc] != 'I' && !vis[nr][nc])
				{
					q.push({ nr,nc });
					tomb[nr][nc] = 'I';
					vis[nr][nc] = true;
					cnt++;

				}
			}


		}
		if(cnt <= 64)
			floors.push_back(cnt);
		
	
	}
	while (room.first != -1 && room.second != -1);
	

	sort(floors.begin(), floors.end(),mda);
	int cnt = 0;
	while (!floors.empty() && n >= floors[0])
	{
		cnt++;
		n -= floors[0];
		floors.erase(floors.begin());
	}

	if (cnt == 1)
		cout << "1 room, 1 square metre(s) left over";
	else

		cout << cnt << " rooms, " << n << " square metre(s) left over";

	return 0;
}
