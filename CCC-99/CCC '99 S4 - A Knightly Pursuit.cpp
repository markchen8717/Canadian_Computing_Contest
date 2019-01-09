
#include <bits/stdc++.h>
//Q querries, for each:
//given a chess board of dimmensions rxc
//board contains a pawn at (pr,pc), and a knight at (kr,kc)
//pawn moves first, then knight
//pawn moves one square at a time in the direction of the top of board
//knight moves in 'L' patters, a total of 8
//if possible:
	//Find minimum required moves for knight to land on pawn (win) 
#define win(x) cout<<"Win in "<<x<<" knight move(s).\n"
	//Find minimum required moves for knight to land immediately one squre
#define stale(x) cout<<"Stalemate in "<<x<<" knight move(s).\n"
		//in front of pawn (stalemate)
	//Find number of moves knight makes before pawn wins (lose)
#define lose(x) cout<<"Loss in "<<x<<" knight move(s).\n"
//use bfs to compute the shortest path for the knight to all squares on the board
//for each square the pawn will land, check for win or stalemate,
	//if there exist a value m that satisfies
		//pawnDis = 2m + knightDis
		//m >=0, integers
		//win in knightDis+2m moves
	//if there exist a value n that statisfies
		//pawnDis-1 = 2nknightDis
		//n >= 0, integers
		//stale in knightDis+2n moves
	
	//if no win or stalemate, it is a lose 

using namespace std;
int Q, dis[110][110], r, c, pr, pc, kr, kc;

void bfs()
{
	memset(dis, -1, sizeof(dis));
	dis[kr][kc] = 0;
	queue<pair<int, int>> q;
	q.push({ kr,kc });
	while (!q.empty())
	{
		auto top = q.front();
		q.pop();
		int row = top.first, col = top.second;
		int dr []= { -2,-1,1,2,2,1,-1,-2 };
		int dc []= {1,2,2,1,-1,-2,-2,-1};
		for (int i = 0; i < 8; i++)
		{
			int newR = row + dr[i], newC = col + dc[i];
			if (newR >= 1 && newR <= r && newC >= 1 && newC <= c)
			{
				if (dis[newR][newC] == -1 || dis[row][col] + 1 < dis[newR][newC])
				{
					dis[newR][newC] = dis[row][col] + 1;
					q.push({ newR,newC });
				}
			}
		}
	}
}

bool isInt(double x)
{
	return double(int(x)) == x;
}

int main()
{
	cin >> Q;
	while (Q--)
	{
		cin >> r >> c >> pr >> pc >> kr >> kc;
		pr = r - pr + 1;
		kr = r - kr + 1;
		bfs();
		bool winOrStale = false;
		for (int s = pr-1; s >= 1; s--)
		{

			int kdis = dis[s][pc];
			if (kdis == -1) // if knight cant land on this square
				continue;
			int pdis = pr - s;
			
			double m = (pdis-kdis) / 2.0;
			double n = (pdis-1-kdis) / 2.0;


			if (isInt(m) && m >= 0 && s != 1)//you lose when s =1, pawn goes first
			{
				win(kdis + m * 2);
				winOrStale = true;
				break;
			}
			else if (isInt(n) && n >= 0)
			{
				stale(kdis + n * 2);
				winOrStale = true;
				break;
			}
		}
		if (!winOrStale)
		{
			lose(pr - 2);
		}
	}
	return 0;
}
