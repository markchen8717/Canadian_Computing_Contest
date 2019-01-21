#include <iostream>
#include<bits/stdc++.h>

//input are the cost of a PINK, GREEN,RED,and ORANGE ticket, followed by 
	//the exact amount of money to be raised by selling tickets
//output all combinations of tickets that produce exactly the desired amount
	// to be raised
//combinations may appear in any order
//output the total number of combinations found
//output the smallest number of tickets to print to raise the desired
	//amount so that printing cost is minimized
//using nested loops, exhaustive search all possible combinations of tickets
	//keeping count of the minimum numbers of tickets

using namespace std;
int P, G, R, O, V;

int main() {
	cin >> P >> G >> R >> O >> V;

	int cnt = 0;
	int comb = 0;
	int least = 0x7fffffff;

	for (int p = 0; p <= V / P; p++)
	{
		for (int g = 0; g <= V / G; g++)
		{
			for (int r = 0; r <= V / R; r++)
			{
				for (int o = 0; o <= V / O; o++)
				{


					cnt = p * P + g * G + r * R + o * O;

					if (cnt == V)
					{
						cout << "# of PINK is " << p << " # of GREEN is " << g << " # of RED is " << r << " # of ORANGE is " << o << "\n";
						comb++;
						least = min(least, p + g + r + o);
					}

				}
			}
		}
	}
	cout << "Total combinations is " << comb << "." << "\n";
	cout << "Minimum number of tickets to print is " << least << ".";


}
