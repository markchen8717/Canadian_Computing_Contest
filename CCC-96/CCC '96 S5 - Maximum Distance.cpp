#include <iostream>

//given equal length arrays x and y, with length up to 10^5
	//elements are SORTED in dending order
//find the max dis
	//dis = j-i, if y[j] >= x[i], for all indices of i in x, and j in y, respectively
	//else dis = 0
//for all indices i in x, binary search for the greatest index j in y, such that y[j] >= x[i]
	//update max distance

using namespace std;
int q, n, s1[100004], s2[100004], dis;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> q;
	for (int i = 0; i <q; i++)
	{
		cin >> n;
		for (int k = 0; k < n; k++)
			cin >> s1[k];
		for (int k = 0; k < n; k++)
			cin >> s2[k];
		dis = 0;
		for (int k = 0; k <n;k++)
		{

			int left, right, middle;
			left = k + 1;
			if (left >= n)
				break;
			right = n - 1;

			while (left <= right)
			{
				middle = (left + right) / 2;
				if (s2[middle] >= s1[k])
					left = middle + 1;
				else
					right = middle - 1;
			}
			if (middle - k > dis)
				dis = middle - k;





		}
		cout << "The maximum distance is " << dis << "\n";
	}

	return 0;
}
