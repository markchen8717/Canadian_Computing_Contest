
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
//inout is three strings
//Each character in these strings have a unique integer representation
//Summing up the integer representation of the first two strings should give
		//the integer representation of the third string

//first create a set of all the unique characters in the strings
//let k be the number of unique characters in the strings

//generate all possible combinations of k digit pins , and all permuations of each pin (essentially, numbers with
//leading zeros count too)
//test if such mapping of characters and integers will pass




int Q;
set<char> allChars;
vector<int>legend(100);
string first, second, third;



bool check()
{
	
	if (!legend[first[0]] || !legend[second[0]] || !legend[third[0]])
		return 0;
	int a = first.length() - 1;
	int b = second.length() - 1;
	int c = third.length() - 1;
	int carry = 0;
	int pass = true;
	while (c >= 0 && pass)
	{
		int ans = carry;
		carry = 0;
		ans = (a >= 0) ? ans + legend[first[a--]] : ans+0;
		ans = (b >= 0) ? ans + legend[second[b--]] : ans+0;
		if (ans >= 10) {
			carry = 1; ans -= 10;
		}
		
		pass = legend[third[c--]] == ans;

	}
	return pass && !carry;
}
void output()
{
	for (int i = 0; i < first.length(); i++)
		cout << legend[first[i]];
	cout << "\n";
	for (int i = 0; i < second.length(); i++)
		cout << legend[second[i]];
	cout << "\n";
	for (int i = 0; i < third.length(); i++)
		cout << legend[third[i]];
	cout << "\n";
}
void allCombos()
{
	//int cnt = 0;
	vector<int>bitset;
	for (int i = 1; i <= 10 - allChars.size(); i++)
	{
		bitset.push_back(0);
	}
	for (auto x : allChars)
	{
		bitset.push_back(1);
	}

	
	do {
	
		vector<int>pin;
		for (int i = 0; i < 10; i++) {
			if (bitset[i])
				pin.push_back(i);
		}
		sort(pin.begin(), pin.end());
		do {
			//create legend
			auto j = allChars.begin();
			auto k = pin.begin();
			while (j != allChars.end() && k != pin.end())
			{
				legend[*j] = *k;
				j++;
				k++;
			}
		
			if (check()) {
				output();
				return;
			}
			/*
			for (auto x : allChars)
				cout << legend[x];
*/
			//cout << "\n";
			//cnt++;
		} while (next_permutation(pin.begin(), pin.end()));

	} while (next_permutation(bitset.begin(), bitset.end()));

	//cout << cnt;
}

int main()
{
	cin >> Q;
	while (Q--)
	{
		allChars.clear();

		cin >> first >> second >> third;
		for (int i = 0; i < first.length(); i++)
			allChars.insert(first[i]);
		for (int i = 0; i < second.length(); i++)
			allChars.insert(second[i]);
		for (int i = 0; i < third.length(); i++)
			allChars.insert(third[i]);
		allCombos();
		cout << "\n";
	}




}
