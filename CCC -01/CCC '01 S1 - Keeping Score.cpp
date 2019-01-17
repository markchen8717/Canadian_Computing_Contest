#include <bits/stdc++.h>
#define obforall(i,a) for( const auto& i : a)
#define modforall(i,a) for (auto&& i : a)

using namespace std;

//Ace = 4 points
//king = 3 points
//queen = 2 points
// jack = 1 point
// 10 is represented as T
// suits club (c) diamonds (d) hearts (h) spades (s)
//void: a hand without a particular suit = 3 points
//singleton:: a hand with only one card from a particular suit = 2 points
//doubleton : a hand with only two card from a particular suit = 1 point
//given thirteen cards, evaluate the # of poitns in the hand
//suits will appear in increasing alphabetical order
//no dupilcate cards within each suit
//output in table form
//use a map and array
//format output with setw()

string c = "Clubs ", d="Diamonds ", h="Hearts ", s="Spades ";
int  arr[4][2];
map<char, int> m = { {'1',0},{'2',0},{'3',0},{'4',0} ,{'5',0},{'6',0},
{'7',0},{'8',0},{'9',0},{'T',0},{'J',1},{'Q',2},{'K',3},{'A',4} };
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string input;
	cin >> input;
	char tmp;
	for (auto x : input)
	{
		if (x == 'C' || x == 'D' || x == 'H' || x == 'S')
		{
			tmp = x; continue;
		}
		if (tmp == 'C')
		{
			c.push_back(x);
			c.push_back(' ');
			arr[0][0] += m[x];
			arr[0][1]++;
		}
		else if (tmp == 'D')
		{
			d.push_back(x);
			d.push_back(' ');
			arr[1][0] += m[x];
			arr[1][1]++;
		}
		else if (tmp == 'H')
		{
			h.push_back(x);
			h.push_back(' ');
			arr[2][0] += m[x];
			arr[2][1]++;
		}
		else
		{
			s.push_back(x);
			s.push_back(' ');
			arr[3][0] += m[x];
			arr[3][1]++;
		}
	}
	
	for (int i = 0; i < 4; i++)
	{
		if (arr[i][1] == 0)
			arr[i][0] += 3;
		else if(arr[i][1] == 1)
			arr[i][0] += 2;
		else if(arr[i][1] == 2)
			arr[i][0] += 1;
	}
	int longest = max(max(c.length(), d.length())
		, max(h.length(), s.length()));
	cout << "Cards Dealt" << setw(longest) << "Points\n";
	cout << setw(0) << c << setw(longest+10-c.length())<<arr[0][0] << "\n";
	cout << setw(0) << d << setw(longest + 10 - d.length())<<arr[1][0] << "\n";
	cout << setw(0) << h << setw(longest + 10 - h.length())<<arr[2][0] << "\n";
	cout << setw(0) << s << setw(longest + 10 - s.length())<<arr[3][0] << "\n";
	cout << setw(longest+8) << "Total " << arr[0][0] + arr[1][0] + arr[2][0] + arr[3][0];
	return 0;
}

