




#include <bits/stdc++.h>
#define obforall(i,a) for( const auto& i : a)
#define modforall(i,a) for (auto&& i : a)

using namespace std;

//start with x quarters
//first machine pays 30 quarters every 35th try
//second machine pays 60 quarters every 100th try
//third machine pays 9 quarters every 10th try
//each machine costs one quarter each time, play one after the other
//output the number of times you can play

//play the machine thats closest to payout
int x, cnt,machine[3];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> x;
	for (int i = 0; i < 3; i++)
		cin >> machine[i];
	int cur = 0;
	while (x)
	{
		cur %= 3;
		cnt++;
		x--;
		machine[cur]++;
		cur++;
		
		if (machine[0]==35)
			x += 30,machine[0]=0;
		else if (machine[1] ==100)
			x += 60,machine[1]=0;
		else if (machine[2]==10)
			x += 9,machine[2]=0;
		

	}
	cout << "Martha plays "<<cnt<<" times before going broke.";



	return 0;
}

