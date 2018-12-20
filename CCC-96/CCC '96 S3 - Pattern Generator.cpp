#include<bits/stdc++.h>

//print all binary numbers with a length of N with K ones in decending order
//start with all ones on the left side, and move the right most one all the way to the right
//repeat for the remaining

//Classification:
//recursiion
//permutation (std library) <======
using namespace std;

int C, N, K;
stack <string> out;
int main()
{
	cin >> C;
	while (C--)
	{
		cin >> N >> K;
		vector<int> arr;

		for (int i = 1; i <= N; i++)
		{
			if (i <= N - K)
			{
				arr.push_back(0);
			}
			else
			{
				arr.push_back(1);
			}
		}


		cout << "The bit patterns are\n";
		do {
			string tmp = "";
			for (auto x : arr)
				tmp += to_string(x);
			out.push(tmp);
		} while (next_permutation(arr.begin(), arr.end()));
		while (!out.empty())
		{
			cout << out.top() << "\n";
			out.pop();
		}
		cout << "\n";



	}
	return 0;
}
