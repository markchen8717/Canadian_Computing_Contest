#include <bits/stdc++.h>
using namespace std;

// A to J (giving the row)
//1  to 9 (giving the column)
//values include
	//as an integer from 0 to 1000
	//as a sum of the values of up to 10 other cells (A1+A4+A5)
//Cell values may be interdependent 
	//a1 - b6 - b8 - etc
//cell values that depend on themselves are undefined 
	//a1 - b6 - a1 
//cell values that depend of undefined cells are also undefined
//undefined cells are to be denoted by *
//output all cell values 

//dfs interdependent cells to either obtain its value or undefined behaviour
//undefined when there exists a path starting at te root cell back to the root cell

bool vis[10][9];

vector<pair<int, int>> adj[10][9];
long long int val[10][9];

int dfs(int row, int col,set <pair<int,int>> path)
{
	if (vis[row][col])
		return val[row][col];
	if (path.count({ row,col }))
	{
		val[row][col] = -1;
		vis[row][col] = 1;
		return -1;
	}
	else
		path.insert({ row,col });
	int cnt = val[row][col];
	for (auto x : adj[row][col])
	{
		int tmp = dfs(x.first, x.second, path);
		if ( tmp< 0)
		{
			val[row][col] = -1;
			vis[row][col] = 1;
			return -1;
		}
		else
			cnt += tmp;
	}
	val[row][col] = cnt;
	vis[row][col] = 1;
	return cnt;
}

int main()
{

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			string input;
			cin >> input;
			if (input[0] >= 65 && input[0] <= 74)
			{

				if (input.length() == 2)
				{
					adj[i][j].push_back({ input[0] - 65,input[1] - 49 });
					continue;
				}
				auto it = input.find('+');

				while (it != string::npos)
				{
					int row = input[it - 2] - 65;
					int col = input[it - 1] - 49;
					adj[i][j].push_back({ row,col });
					it = input.find('+', it + 1);
				}
				int len = input.length();
				adj[i][j].push_back({ input[len - 2] - 65,input[len - 1] - 49 });
			}
			else
			{
				val[i][j] = stoi(input);
			}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 9; j++)
		{

			if (adj[i][j].size())
			{
				set<pair<int, int>> path;
				dfs(i, j,path);
			}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (val[i][j] >= 0)
				cout << val[i][j];
			else
				cout << '*';
			cout << " ";
		}
		cout << "\n";
	}
}
