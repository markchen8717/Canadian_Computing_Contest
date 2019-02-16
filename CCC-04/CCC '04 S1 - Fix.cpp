#include <bits/stdc++.h>
using namespace std;
//A collection of words is prefix-free if no word is a prefix of any other word.
//A collection of words is suffix-free if no word is a suffix of any other word.
//If both false, the collection is fix-free

// A word X is a prefix of word Y if X consists of the first n characters of Y, in order, for some n. 
//Similarly, a word X is a suffix of Y if X consists of the last n characters of Y, in order, for some n.

//output whether a collection is fix-free

int N;
string collection[3];

bool isSuffix(string a, string b)
{
	if (a.length() > b.length())
		return false;
	auto it = mismatch(a.begin(), a.end(), b.begin());
	return it.first == a.end();
}
bool isPrefix(string a, string b)
{
	if (a.length() > b.length())
		return false;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	auto it = mismatch(a.begin(), a.end(), b.begin());
	return it.first == a.end();
}


bool isFixFree()
{
	return !(isPrefix(collection[0], collection[1]) || isPrefix(collection[0], collection[2])
		|| isPrefix(collection[1], collection[0]) || isPrefix(collection[1], collection[2])
		|| isPrefix(collection[2], collection[0]) || isPrefix(collection[2], collection[1]))
		&&
		!(isSuffix(collection[0], collection[1]) || isSuffix(collection[0], collection[2])
			|| isSuffix(collection[1], collection[0]) || isSuffix(collection[1], collection[2])
			|| isSuffix(collection[2], collection[0]) || isSuffix(collection[2], collection[1]));
}
int main()
{
	cin >> N;
	while (N--)
	{
		for (int i = 0; i < 3; i++)
			cin >> collection[i];
		if (isFixFree())
			cout << "Yes\n";
		else
			cout << "No\n";

	}
}
