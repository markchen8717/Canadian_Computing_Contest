#include<bits/stdc++.h>


//n lines of text
//ouput each line with all four letter words censored with asterix
//use a stringstream

using namespace std;

int N;
int main()
{
	cin >> N;
	cin.ignore();
	while (N--)
	{
		string input;
		getline(cin, input);
		stringstream ss(input);
		string word;
		while (ss >> word)
		{
			if (word.length() == 4)
				cout << "****";
			else
				cout << word;
			cout << " ";
		}
		cout << "\n";
	}
}

