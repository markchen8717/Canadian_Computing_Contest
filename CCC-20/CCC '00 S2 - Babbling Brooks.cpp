
#include <bits/stdc++.h>
//streams are labelled 1 to m, left to right
// a split increments, a merge decrements, streams are renumbered after
//a line containing 99 means a split 
	//followed by the # of the stream that is split
	//followed by the % to the left, remaning to the right
//a line containing 88 indicate a join
	//followed by the # of the stream to join to its right
//input ends with 77
//output the flow in rivers 1 through m at the foot of the mountain
	//real numbers rounded to the nearest integer

//use a vector of doubles to simulate the streams

using namespace std;
int N;

int main() {
	cin >> N;
	vector<double> streams(N + 1);
	for (int i = 1; i <= N; i++)
	{
		cin >> streams[i];
	}

	int a, b;
	double c;
	cin >> a;
	while (a != 77)
	{
		switch (a)
		{
		case 99:
		{
			cin >> b >> c;
			double mom = streams[b];

			streams.insert(streams.begin() + b + 1, mom*(1 - (c / 100)));
			streams.insert(streams.begin() + b + 1, mom*(c / 100));
			streams.erase(streams.begin() + b);

			break;
		}
		case 88:
		{
			cin >> b;
			streams.insert(streams.begin() + b, streams[b] + streams[b + 1]);
			streams.erase(streams.begin() + b + 1);
			streams.erase(streams.begin() + b + 1);
			break;
		}
		}
		cin >> a;
	}

	for (int i = 1; i <= streams.size() - 1; i++)
		cout << (int)streams[i] + 0.5 << " ";

	return 0;
}
