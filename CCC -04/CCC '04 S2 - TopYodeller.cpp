 
#include <bits/stdc++.h>
using namespace std;



//A yodeller’s rank is j+1 if j yodellers have a cumulative score higher than their score.
//After each round, each yodeller’s cumulative score is calculated and a rank is assigned
//there may be multiple yodellers at the same rank
//Yodellers are assigned contestant numbers from 1 to  n
//score assigned to a yodeller in any given round is an integer between −1000 and 1000,

//output Yodeller x is the TopYodeller: score y, worst rank z
	//where x is the contestant number
	//y  is their total score after the competition
	//z  is their worst rank at any time during the competition
// listed by increasing competitor number if tie exists

//std solution with vectors and custom sorts 
//over complicated things
//simple 1d array is sufficient and much more effective

struct yod {
	int x,y,z,r;
};
int N, R;

bool cmpR(yod a, yod b)
{
	return a.y > b.y;
}
bool cmpN(yod a, yod b)
{
	return a.x < b.x;
}
bool cmpF(yod a, yod b)
{
	if (a.y == b.y)
		return  a.x < b.x;

	else 
		return a.y > b.y;
}
int main()
{
	cin >> N >> R;
	vector<yod> con(N);
	vector<yod> rank(N );
	for (int i = 1; i <= N; i++)
	{
		yod tmp;
		tmp.x = i;
		tmp.y = 0;
		tmp.z = -1;
		tmp.r = 0x3f3f3f3f;
		con[i-1] = tmp;
		rank[i-1] = tmp;
	}
	while (R--)
	{
		for (int i = 1; i <= N; i++)
		{
			int score;
			cin >> score;
			con[i-1].y += score;
		}
		rank = con;
		sort(rank.begin(), rank.end(),cmpR);
		
		for (int i = 1; i <= N; i++)
		{		
			int actual = i;
			int score = rank[i-1].y;
			for (int j = i-2; j >= 0; j--)
			{
				if (score == rank[j].y)
					actual = rank[j].r;
				else
					break;
			}
			rank[i-1].r = actual;
			rank[i-1].z = max(rank[i-1].z, rank[i-1].r);

		}
		sort(rank.begin(), rank.end(), cmpN);
		con = rank;

	}
	sort(con.begin(), con.end(), cmpF);
	int winner = con[0].y;
	for (auto x : con)
	{
		if (x.y == winner)
		{
			cout << "Yodeller "<<x.x<<" is the TopYodeller: score " << x.y<<", worst rank "<< x.z<<"\n";
		}
	}
}
