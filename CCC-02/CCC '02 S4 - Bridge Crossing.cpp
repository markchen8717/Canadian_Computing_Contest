#include <iostream>
#include <bits/stdc++.h>

//there is a limit of M people per group to cross a bridge
//the time to cross for a group depends on the slowest person
//people are in a queue
//groups can be size of x where x <=M
//goal is to get everyone over in the shortest time maintaining the order of the queue

//dynamic programming approach
//dp[i][j] is the shortest time it takes for all i people to cross with bridge size of j
//path[i] is the length of the group with person i as the last
//for every i person, traverse all k possible potential group mates and find the fastest
	//group that will cross with i as last person
	//use previously computed best times through dp to help find new best times for more people

using namespace std;


pair< string, int> people[101];
int dp[101][21];
int path[101];


int M, Q;
int main() {
	cin >> M >> Q;
	for (int i = 1; i <= Q; i++)
	{
		string name;
		int  speed;
		cin >> name >> speed;
		people[i] = make_pair(name, speed);
	}

	for (int i = 1; i <= Q; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (j == 1)
			{
				dp[i][j] = dp[i - 1][1] + people[i].second;
				path[i] = 1;
			}
			else
			{
				int slowest = people[i].second;
				int best = 0x3f3f3f3f;
				for (int k = 1; k <= j && i-k+1 >=1; k++) //travers all k possible group mates
				{
					slowest = max(slowest, people[i - k + 1].second);
					if (best > dp[i - k][j] + slowest)
					{
						best = dp[i - k][j] + slowest;
						path[i] = k;

					}
				}
				dp[i][j] = best;
			}

		}
	}

	stack <string > s;
	int num = path[Q];
	int person = Q;
	
	while (person > 0)
	{
		string tmp = people[person].first;
		for (int i = 1; i < num; i++)
		{
			tmp = people[person - i].first + " " + tmp;
		}
		s.push(tmp);
		
		person -= num;
		if (person <= 0)
			continue;
		num = path[person];
	}

	cout << "Total Time: " << dp[Q][M] << "\n";
	while (!s.empty())
	{
		cout << s.top() << "\n";
		s.pop();
	}
	
}
