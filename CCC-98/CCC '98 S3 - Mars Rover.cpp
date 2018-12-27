
#include<bits/stdc++.h>

//for q querries
//simulate a robot's displacement starting from initial position
//output the distance of the shortest path back to initial position
//ouptut the instructions to the shortest path back to inital postiion
// each query is separated by an empty line

//only 4 directions
//1 - N
//2 - E
//3 - S
//4 - W
//initial direction set to 1

//three robot instructions
#define Forward(N) cout<<1<<"\n"<<abs(N)<<"\n"  // move in direction n units
#define CCW cout<<3<<"\n" //3 turn ccw
#define CW cout<<2<<"\n" //2 turn cw

//find vertical and horizontal displacement
	//set 1 & 2 as positive directions
	//set 3 & 4 as negative directions


using namespace std;
int Q;
short dir = 1;
int hor = 0, vert = 0;
void move(int u)
{
	switch (dir) {
		case 1:
		{
			vert += u;
			break;
		}
		case 2:
		{
			hor += u;
			break;
		}
		case 3:
		{
			vert -= u;
			break;
		}
		case 4:
		{
			hor -= u;
			break;
		}
	}
}

int dis(int u, int v)
{
	int ans = (abs(u - v) < 3) ? abs(u - v) : 1;
	return ans;
}

void goTo(int u, int v)
{
	if (dis(u,v))
	{
		if (u == 4 && v == 1)
			CW;
		else if (u == 1 && v == 4)
			CCW;
		else if (u < v && dis(u,v) == 1)
			CW;
		else if (u > v && dis(u,v) == 1)
			CCW;
		else
			CCW, CCW;  //output is CCW biased in scenarios where CW can be used
	}
}

void home()
{
	if (!hor && !vert)
		return;
	int dir_H = (hor > 0) ? 4 : 2;
	int dir_V = (vert > 0) ? 3 : 1;
	int turn = (dis(dir,dir_H) < dis(dir,dir_V)) ? dir_H : dir_V;
	if (turn == dir_H && hor || turn == dir_V && vert)
	{
		goTo(dir, turn);
		if (turn == dir_H)
			Forward(hor);
		else
			Forward(vert);
		dir = turn;
	}
	
	turn = (turn == dir_H) ? dir_V : dir_H;
	if (turn == dir_H && hor || turn == dir_V && vert)
	{
		goTo(dir, turn);
		if (turn == dir_H)
			Forward(hor);
		else
			Forward(vert);
	}

}

int main()
{
	cin >> Q;
	while (Q--)
	{
		dir = 1;
		hor = 0, vert = 0;
		int a, b;
		while(cin>>a && a)
		{
			switch (a)
			{
				case (1) :
					cin >> b;
					move(b);
					break;
				case (3):
					dir = (dir - 1 < 1) ? 4 : dir-1;
					break;
				case (2) :
					dir = (dir + 1 > 4) ? 1 : dir + 1;
					break;
			}
		}
		cout << "Distance is " << abs(vert) + abs(hor) << "\n";
		home();
		cout << "\n";
	}

	
}

