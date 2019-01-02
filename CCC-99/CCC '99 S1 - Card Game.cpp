
#include <bits/stdc++.h>

using namespace std;
//52  cards in the deck
//four of each
	//two, three, four, five, six, seven, eight, nine, ten, jack, 
	//high cards: queen, king, ace
//A turns over top card before B, alternating
//scoring:
	//4 points for turning an ace with no high cards in the next 4 turns
	//3 points for turning a king with no high cards in the next 3 turns
	//2 points for turning a queen with no high cards in the next 2 turns
	//1 points for turning a jack with no high cards in the next turn
//input contains all cards each turn starting with the first
//output scoring message each time a player scores
#define score(id,n)  cout<<"Player "<<id<<" scores " <<n<<" point(s).\n";
	//at the end, pritn total score for each player
#define final(id,n) cout<<"Player " <<id <<": "<<n << " point(s).\n";







short player[2][5], A, B;
int main()
{
	memset(player, -1, sizeof(player));
	
	for (int i = 1; i <= 52; i++)
	{
		string input;
		cin >> input;
		
		short id = (i % 2) ? 0 : 1; //A=0 B=1  
									
		
		
									
									
		//reset counters if high card
		if (input == "ace" || input == "king" || input == "queen" || input == "jack")
		{
			memset(player, -1, sizeof(player));
		}
		else //deduct counters
		{
			for (int j = 1; j <= 4; j++) //deduct counters
			{
				if (player[0][j] > 0)player[0][j]--;
				if (player[1][j] > 0) player[1][j]--;
			}
		}



		//set new counters for current player
		if (input == "ace")
			player[id][4] = 4;
		else if (input == "king")
			player[id][3] = 3;
		else if (input == "queen")
			player[id][2] = 2;
		else if (input == "jack")
			player[id][1] = 1;

		//keep score
		for (int j = 1; j <= 4; j++) //deduct counters
		{
			if (player[0][j] == 0) { score("A", j); player[0][j] = -1; A += j; }
			else if (player[1][j] == 0) { score("B", j); player[1][j] = -1; B += j; }
		}
	}
	final("A", A);
	final("B", B);

}

