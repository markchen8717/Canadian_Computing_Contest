 
#include <bits/stdc++.h>



using namespace std;
//given a grid with r rows and c columns with obstacles at some squares
//determine all possible final positions starting from an random initial
	//position after m given moves
	//F to move forward
	//L to turn 90 degrees ccw
	//R to turn 90 degrees cw
//'.' denotes a valid grid
//'X' denotes a grid with an ivalid grid
//output the grid with '*' to denote possible final positions
//take every valid grid and perform the m given moves in reverse, if ok
	//mark it as potential final position



#define obforall(i,a) for( const auto& i : a)
#define modforall(i,a) for (auto&& i : a)

#define xc .first
#define yc .second

char grid[380][90];

vector<char>moves;
int r, c, m;

bool isOk(int x, int y)
{
	
	int row[4] = { 1,0,-1,0 };
	int col[4] = { 0,-1,0,1 };
	bool output = false;
	for (int k = 0; k < 4; k++)
	{
		int i = x; int j = y;
		int ori = k;
		for (auto d : moves)
		{
			if (i > r || i <1 || j >c || j < 1 || grid[i][j] == 'X')
				break;
			if (d == 'F')
			{
				i += row[ori]; 
				j += col[ori];
			}
			else if (d == 'R')
			{
				ori = (ori + 1 > 3) ? 0 : ori + 1;
			}
			else
			{
				ori = (ori - 1 < 0)? 3:ori - 1;
			}
		}
		if (!(i > r || i <1 || j >c || j < 1 || grid[i][j] == 'X'))
		{
			output = true; break;
		}
	}
	return output;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> r >> c;
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			cin >> grid[i][j];
	cin >> m;
	while (m--) //reverse store moves
	{
		char tmp;
		cin >> tmp;
		if (tmp == 'L')
			tmp = 'R';
		else if (tmp == 'R')
			tmp = 'L';
		moves.insert(moves.begin(), tmp);
	}
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++) {
			if(isOk(i, j))
				grid[i][j]='*';
		}
	}
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++) 
		{
			cout << grid[i][j];
		}
		cout << "\n";
	}


	return 0;
}
