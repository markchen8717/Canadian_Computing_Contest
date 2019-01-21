#include <bits/stdc++.h>

//given two sequences of strings A, and B
	//a positive integer m;
//find if there exists an integer sequence C of length k, m>k>0
	// where for each int i in C, A[i1]+A[i2]...+A[ik] = B[i1]+B[i1]...+B[ik]
//output k
	//and all int i in C
	//separated by blank lines
	//if no possible solution output
		//"No solution."
//recursively try all strings untill one works?
	//base cases
		//if more than k strings are added, its over
		//if string matches, and not empty, done


using namespace std;

#define obforall(i,a) for( const auto& i : a)
#define modforall(i,a) for (auto&& i : a)

#define xc .first
#define yc .second


vector<string>A, B;
int m, n;



bool tryAll(string a, string b, vector<int> C)
{
	if (C.size() >= m)
		return 0;
	else if (a == b && a.length() > 0)
	{
		cout << C.size() << "\n";
		for (auto x : C)
			cout << x << "\n";
		return 1;
	}
	else
	{
		bool f = false;
		for (int i = 1; i <= n; i++)
		{
			vector<int>tmp = C;
			tmp.push_back(i);
			f = f || tryAll(a + A[i - 1], b + B[i - 1], tmp);
		}
		return f;
	}
}




int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> m >> n;
	for (int i = 1; i <= n; i++)
	{
		string tmp;
		cin >> tmp;
		A.push_back(tmp);
	}
	for (int i = 1; i <= n; i++)
	{
		string tmp;
		cin >> tmp;
		B.push_back(tmp);
	}
	vector<int> empty;
	if (!tryAll("", "", empty))
		cout << "No solution.";
	return 0;
}
